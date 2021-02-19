#ifndef JSONPARSER_HPP_
#define JSONPARSER_HPP_

#include <cwchar>
#include <locale>
#include <codecvt>
#include <iterator>
#include <string>

#include "WistreamIterator.hpp"
#include "JsonError.hpp"

enum Encoding {
    ascii,
    utf8,
    utf16
};

template<typename Holder, typename Buffer, typename Worker, typename It> struct ParserData {
    ParserData(It &begin, It const &end, Worker &worker) noexcept : _begin{begin}, _end{end}, _worker{worker} {
    }
    ParserData(ParserData<Holder, Buffer, Worker, It> const &) noexcept = delete;
    ParserData(ParserData<Holder, Buffer, Worker, It> &&) noexcept = delete;
    ~ParserData() = default;
    It &_begin;
    It const &_end;
    Worker &_worker;
    using HolderType = Holder;
    HolderType _c;
    using BufferType = Buffer;
    bool _eof = false;
    std::size_t _nested = 0;
};

template<typename Data> static bool next(Data &data) noexcept {
    return ++data._begin == data._end || data._eof ? !(data._eof = true) : true;
}

template<typename Data> static bool skipws(Data &data, bool const eop = false) {
    while (!data._eof && ((typename Data::HolderType)' ' == *data._begin || (typename Data::HolderType)'\n' == *data._begin || (typename Data::HolderType)'\t' == *data._begin || (typename Data::HolderType)'\r' == *data._begin)) {
	if (!next(data) && !eop)
	    error("skipping white spaces but got eof");
    }
    data._c = *data._begin;
    return !data._eof;
}

template<typename Data> static void consume(Data &data) noexcept {
    next(data);
    data._c = data._eof ? 0 : *data._begin;
}

template<typename Data> static void expecter(Data &data, typename Data::HolderType const c) {
    certify(c == data._c, std::string{"expecting \'"} + (char)c + "\'");
    consume(data);
}

template<typename Data> static bool isHexDigit(Data &data) {
    return (47 < data._c && 58 > data._c) || (96 < data._c && 103 > data._c) || (64 < data._c && 71 > data._c);
}

template<typename Data> static void hex(Data &data, typename Data::BufferType &buf) {
    for (unsigned short int i = 0; i < 4; ++i) {
	consume(data);
	certify(isHexDigit(data), "expected 4 hex digit in string after \\u");
	buf += data._c;
    }
}

template<typename Data> static void string(Data &data) {
    typename Data::BufferType buf;
    expecter(data, (typename Data::HolderType)'\"');
    bool eos = false;
    while (!eos && !data._eof) {
	if ((typename Data::HolderType)'\"' == data._c)
	    eos = true;
	else if ((typename Data::HolderType)'\\' == data._c) {
	    consume(data);
	    if ((typename Data::HolderType)'\"' == data._c || (typename Data::HolderType)'\\' == data._c || (typename Data::HolderType)'/' == data._c)
		(buf += (typename Data::HolderType)'\\') += data._c;
	    else if ((typename Data::HolderType)'u' == data._c) {
		(buf += (typename Data::HolderType)'\\') += (typename Data::HolderType)'u';
		hex(data, buf);
	    } else
		switch (data._c) {
		case (typename Data::HolderType)'b': {
		    buf += (typename Data::HolderType)'\b';
		    break;
		}
		case (typename Data::HolderType)'f': {
		    buf += (typename Data::HolderType)'\f';
		    break;
		}
		case (typename Data::HolderType)'n': {
		    buf += (typename Data::HolderType)'\n';
		    break;
		}
		case (typename Data::HolderType)'r': {
		    buf += (typename Data::HolderType)'\r';
		    break;
		}
		case (typename Data::HolderType)'t': {
		    buf += (typename Data::HolderType)'\t';
		    break;
		}
		default:
		    error("bad dereferencing in string");
		}
	} else if ((typename Data::HolderType)32 > data._c) {
	    error("unescaped control char");
	} else
	    buf += data._c;
	consume(data);
    }
    if (data._eof && !eos)
        error("encountered eof in a string");
    data._worker.string(std::wstring{buf.begin(), buf.end()});
}

template<typename Data> static void null(Data &data) {
    char const *nullVerifier = "null";
    do
	expecter(data, (typename Data::HolderType)*nullVerifier);
    while (*++nullVerifier);
    data._worker.null();
}

template<typename Data> static void boolean(Data &data, bool const b) {
    char const *boolVerifier = b ? "true" : "false";
    do
	expecter(data, (typename Data::HolderType)*boolVerifier);
    while (*++boolVerifier);
    data._worker.boolean(b);
}


template<typename Data> static void exponent(Data &data, typename Data::BufferType &buf) {
    if ((typename Data::HolderType)'e' == data._c || (typename Data::HolderType)'E' == data._c) {
	buf += data._c;
	consume(data);
	if ((typename Data::HolderType)'-' == data._c || (typename Data::HolderType)'+' == data._c) {
	    buf += data._c;
	    consume(data);
	}
	digits(data, buf, true);
    }
}

template<typename Data> static void fraction(Data &data, typename Data::BufferType &buf) {
    if ((typename Data::HolderType)'.' == data._c) {
	buf += (typename Data::HolderType)'.';
	consume(data);
	digits(data, buf, true);
    }
}

template<typename Data> void digits(Data &data, typename Data::BufferType &buf, bool const one = false) {
    bool digit = false;
    while ((typename Data::HolderType)47 < data._c && (typename Data::HolderType)58 > data._c) {
        buf += data._c;
	consume(data);
	digit = true;
    }
    if (one && !digit)
        error("expecting a digit");
}

template<typename Data> static void number(Data &data) {
    typename Data::BufferType buf;
    if ((typename Data::HolderType)'-' == data._c) {
	buf += (typename Data::HolderType)'-';
	consume(data);
    }
    if ((typename Data::HolderType)'0' == data._c) {
	buf += (typename Data::HolderType)'0';
	consume(data);
    } else if ((typename Data::HolderType)48 < data._c && (typename Data::HolderType)58 > data._c) {
	buf += data._c;
	consume(data);
	digits(data, buf);
    } else
	error("expecting a digit");
    fraction(data, buf);
    exponent(data, buf);
    data._worker.number(std::stod(std::wstring{buf.begin(), buf.end()}));
}

template<typename Data> static void separator(Data &data) {
    expecter(data, (typename Data::HolderType)':');
    data._worker.pair();
}


template<typename Data> static void pair(Data &data) {
    skipws(data);
    string(data);
    skipws(data);
    separator(data);
    certify(value(data), "early eof in value parsing");
}

template<typename Data> static void object(Data &data) {
    expecter(data, (typename Data::HolderType)'{');
    data._worker.openObject();
    if ((typename Data::HolderType)'}' != data._c) {
	pair(data);
	while ((typename Data::HolderType)',' == data._c) {
	    data._worker.objectSeparator();
	    consume(data);
	    pair(data);
	}
    }
    expecter(data, (typename Data::HolderType)'}');
    data._worker.closeObject();
}

template<typename Data> static void array(Data &data) {
    expecter(data, (typename Data::HolderType)'[');
    data._worker.openArray();
    if ((typename Data::HolderType)']' != data._c) {
        certify(value(data), "early eof in value parsing");
	while ((typename Data::HolderType)',' == data._c) {
	    data._worker.arraySeparator();
	    consume(data);
	    certify(value(data), "early eof in value parsing");
	}
    }
    expecter(data, (typename Data::HolderType)']');
    data._worker.closeArray();
}

template<typename Data> static bool value(Data &&data) {
    return value(data);
}

template<typename Data> static bool value(Data &data) {
    ++data._nested;
    certify(513 > data._nested, "json max depth is 512");
    skipws(data);
    switch (data._c) {
    case (typename Data::HolderType)'{':
	object(data);
	break;
    case (typename Data::HolderType)'\"':
	string(data);
	break;
    case (typename Data::HolderType)'[':
	array(data);
	break;
    case (typename Data::HolderType)'t':
	boolean(data, true);
	break;
    case (typename Data::HolderType)'f':
	boolean(data, false);
	break;
    case (typename Data::HolderType)'n':
	null(data);
	break;
    default:
	if (((typename Data::HolderType)47 < data._c && (typename Data::HolderType)58 > data._c) || (typename Data::HolderType)'-' == data._c) {
	    number(data);
	} else
	    error("wrong identifier");
    }
    --data._nested;
    return skipws(data, true);
}

template<typename Worker, typename It> void runParser(It &begin, It const &end, Worker &worker, Encoding const encoding) {
    switch (encoding) {
    case ascii: {
        ParserData<char, std::string, Worker, It> data{begin, end, worker};
	data._worker.begin();
	value(data);
	data._worker.end();
	certify(data._eof, "eof not reached at end of parsing");
	break;
    }
    case utf8: {
	ParserData<wchar_t, std::wstring, Worker, It> data{begin, end, worker};
	data._worker.begin();
	value(data);
	data._worker.end();
	certify(data._eof, "eof not reached at end of parsing");
	break;
    }
    case utf16: {
	ParserData<char16_t, std::wstring, Worker, It> data{begin, end, worker};
	data._worker.begin();
	value(data);
	data._worker.end();
	certify(data._eof, "eof not reached at end of parsing");
	break;
    }
    default:
	error("encoding type must be ascii, utf-8 or utf-16 :: cannot generate ParserData");
    }
}

template<typename Worker, typename It> typename std::enable_if<!std::is_same<void, typename Worker::ReturnType>::value, typename Worker::ReturnType>::type parseJson(It &&begin, It &&end, Worker &&worker, Encoding const encoding = utf8) {
    runParser(begin, end, worker, encoding);
    return worker();
}

template<typename Worker, typename It> typename std::enable_if<std::is_same<void, typename Worker::ReturnType>::value, void>::type parseJson(It &&begin, It &&end, Worker &&worker, Encoding const encoding = utf8) {
    runParser(begin, end, worker, encoding);
}

template<typename Worker, typename It> typename std::enable_if<!std::is_same<void, typename Worker::ReturnType>::value, typename Worker::ReturnType>::type parseJson(It &&begin, It &&end, Worker &worker, Encoding const encoding = utf8) {
    runParser(begin, end, worker, encoding);
    return worker();
}

template<typename Worker, typename It> typename std::enable_if<std::is_same<void, typename Worker::ReturnType>::value, void>::type parseJson(It &&begin, It &&end, Worker &worker, Encoding const encoding = utf8) {
    runParser(begin, end, worker, encoding);
}

template<typename Worker, typename It> typename std::enable_if<!std::is_same<void, typename Worker::ReturnType>::value, typename Worker::ReturnType>::type parseJson(It &begin, It const &end, Worker &&worker, Encoding const encoding = utf8) {
    runParser(begin, end, worker, encoding);
    return worker();
}

template<typename Worker, typename It> typename std::enable_if<std::is_same<void, typename Worker::ReturnType>::value, void>::type parseJson(It &begin, It const &end, Worker &&worker, Encoding const encoding = utf8) {
    runParser(begin, end, worker, encoding);
}

template<typename Worker, typename It> typename std::enable_if<!std::is_same<void, typename Worker::ReturnType>::value, typename Worker::ReturnType>::type parseJson(It &begin, It const &end, Worker &worker, Encoding const encoding = utf8) {
    runParser(begin, end, worker, encoding);
    return worker();
}

template<typename Worker, typename It> typename std::enable_if<std::is_same<void, typename Worker::ReturnType>::value, void>::type parseJson(It &begin, It const &end, Worker &worker, Encoding const encoding = utf8) {
    runParser(begin, end, worker, encoding);
}

template<typename Worker, typename It> typename std::enable_if<!std::is_same<void, typename Worker::ReturnType>::value, typename Worker::ReturnType>::type parseJson(It &&begin, It &&end, Encoding const encoding = utf8) {
    return parseJson(begin, end, Worker{}, encoding);
}

template<typename Worker, typename It> typename std::enable_if<std::is_same<void, typename Worker::ReturnType>::value, void>::type parseJson(It &&begin, It &&end, Encoding const encoding = utf8) {
    parseJson(begin, end, Worker{}, encoding);
}

template<typename Worker, typename It> typename std::enable_if<!std::is_same<void, typename Worker::ReturnType>::value, typename Worker::ReturnType>::type parseJson(It &begin, It const &end, Encoding const encoding = utf8) {
    return parseJson(begin, end, Worker{}, encoding);
}

template<typename Worker, typename It> typename std::enable_if<std::is_same<void, typename Worker::ReturnType>::value, void>::type parseJson(It &begin, It const &end, Encoding const encoding = utf8) {
    parseJson(begin, end, Worker{}, encoding);
}

template<typename Worker> static void parseJsonFile(std::string const &fileName, Worker &worker, Encoding const encoding) {
    switch (encoding) {
    case ascii: {
	std::ifstream file{fileName};
	certify(file.good(), "bad file");
	file >> std::noskipws;
	std::istream_iterator<char> begin{file}, end{};
        parseJson(begin, end, worker, encoding);
	file.close();
	break;
    }
    case utf8: {
	std::wifstream file{fileName};
	certify(file.good(), "bad file");

#ifdef WIN32
#if _MSC_VER >= 1900
	(file >> std::noskipws).imbue(std::locale(file.getloc(), new std::codecvt_utf8<int16_t, 0x10ffff, std::consume_header>));
#else
	(file >> std::noskipws).imbue(std::locale(file.getloc(), new std::codecvt_utf8<char16_t, 0x10ffff, std::consume_header>));
#endif /* _MSC_VER >= 1900 */
#else
	(file >> std::noskipws).imbue(std::locale(file.getloc(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::consume_header>));
#endif /* WIN32 */

	WistreamIterator<wchar_t> begin{file}, end{};
	parseJson(begin, end, worker, encoding);
	file.close();
	break;
    }
    case utf16: {
	std::wifstream file{fileName};
	certify(file.good(), "bad file");
#ifdef WIN32
#if _MSC_VER >= 1900
	(file >> std::noskipws).imbue(std::locale(file.getloc(), new std::codecvt_utf8<int16_t, 0x10ffff, std::consume_header>));
#else
	(file >> std::noskipws).imbue(std::locale(file.getloc(), new std::codecvt_utf8<char16_t, 0x10ffff, std::consume_header>));
#endif /* _MSC_VER >= 1900 */
#else
	(file >> std::noskipws).imbue(std::locale(file.getloc(), new std::codecvt_utf8<char16_t, 0x10ffff, std::consume_header>));
#endif /* WIN32 */
	WistreamIterator<char16_t> begin{file}, end{};
	parseJson(begin, end, worker, encoding);
	file.close();
	break;
    }
    default:
	error("encoding type must be ascii, utf-8 or utf-16 :: cannot open data stream");
    }
}

template<typename Worker> static void parseJsonString(std::string const &str, Worker &worker, Encoding const encoding) {
    certify(ascii == encoding, "encoding type must be ascii when parsing standard string raw data :: cannot handle utf-8 or utf-16 when working with a non wide string object :: cannot create iterators");
    parseJson(str.cbegin(), str.cend(), worker, encoding);
}

template<typename Worker> typename std::enable_if<!std::is_same<void, typename Worker::ReturnType>::value, typename Worker::ReturnType>::type parseJsonStr(std::string const &str, Worker &&worker, Encoding const encoding = utf8) {
    parseJsonString(str, worker, encoding);
    return worker();
}

template<typename Worker> typename std::enable_if<std::is_same<void, typename Worker::ReturnType>::value, void>::type parseJsonStr(std::string const &str, Worker &&worker, Encoding const encoding = utf8) {
    parseJsonString(str, worker, encoding);
}

template<typename Worker> typename std::enable_if<!std::is_same<void, typename Worker::ReturnType>::value, typename Worker::ReturnType>::type parseJsonStr(std::string const &str, Worker &worker, Encoding const encoding = utf8) {
    parseJsonString(str, worker, encoding);
    return worker();
}

template<typename Worker> typename std::enable_if<std::is_same<void, typename Worker::ReturnType>::value, void>::type parseJsonStr(std::string const &str, Worker &worker, Encoding const encoding = utf8) {
    parseJsonString(str, worker, encoding);
}

template<typename Worker> typename std::enable_if<!std::is_same<void, typename Worker::ReturnType>::value, typename Worker::ReturnType>::type parseJsonStr(std::string const &str, Encoding const encoding = utf8) {
    return parseJsonStr(str, Worker{}, encoding);
}

template<typename Worker> typename std::enable_if<std::is_same<void, typename Worker::ReturnType>::value, void>::type parseJsonStr(std::string const &str, Encoding const encoding = utf8) {
    parseJsonStr(str, Worker{}, encoding);
}

template<typename Worker> void static parseJsonString(std::wstring const &str, Worker &worker, Encoding const encoding) {
    certify(ascii != encoding, "encoding type should not be ascii :: use standard string object for faster ascii parsing");
    certify(utf8 == encoding || utf16 == encoding, "encoding type must be utf8 or utf16 when parsing wide string raw data :: cannot create iterators");
    parseJson(str.cbegin(), str.cend(), worker, encoding);	
}

template<typename Worker> typename std::enable_if<!std::is_same<void, typename Worker::ReturnType>::value, typename Worker::ReturnType>::type parseJsonStr(std::wstring const &str, Worker &&worker, Encoding const encoding = utf8) {
    parseJsonString(str, worker, encoding);
    return worker();
}

template<typename Worker> typename std::enable_if<std::is_same<void, typename Worker::ReturnType>::value, void>::type parseJsonStr(std::wstring const &str, Worker &&worker, Encoding const encoding = utf8) {
    parseJsonString(str, worker, encoding);
}

template<typename Worker> typename std::enable_if<!std::is_same<void, typename Worker::ReturnType>::value, typename Worker::ReturnType>::type parseJsonStr(std::wstring const &str, Worker &worker, Encoding const encoding = utf8) {
    parseJsonString(str, worker, encoding);
    return worker();
}

template<typename Worker> typename std::enable_if<std::is_same<void, typename Worker::ReturnType>::value, void>::type parseJsonStr(std::wstring const &str, Worker &worker, Encoding const encoding = utf8) {
    parseJsonString(str, worker, encoding);
}

template<typename Worker> typename std::enable_if<!std::is_same<void, typename Worker::ReturnType>::value, typename Worker::ReturnType>::type parseJsonStr(std::wstring const &str, Encoding const encoding = utf8) {
    return parseJsonStr(str, Worker{}, encoding);
}

template<typename Worker> typename std::enable_if<std::is_same<void, typename Worker::ReturnType>::value, void>::type parseJsonStr(std::wstring const &str, Encoding const encoding = utf8) {
    parseJsonStr(str, Worker{}, encoding);
}

template<typename Worker> typename std::enable_if<!std::is_same<void, typename Worker::ReturnType>::value, typename Worker::ReturnType>::type parseJson(std::string const &fileName, Worker &&worker, Encoding const encoding = utf8) {
    parseJsonFile(fileName, worker, encoding);
    return worker();
}

template<typename Worker> typename std::enable_if<std::is_same<void, typename Worker::ReturnType>::value, void>::type parseJson(std::string const &fileName, Worker &&worker, Encoding const encoding = utf8) {
    parseJsonFile(fileName, worker, encoding);
}

template<typename Worker> typename std::enable_if<!std::is_same<void, typename Worker::ReturnType>::value, typename Worker::ReturnType>::type parseJson(std::string const &fileName, Worker &worker, Encoding const encoding = utf8) {
    parseJsonFile(fileName, worker, encoding);
    return worker();
}

template<typename Worker> typename std::enable_if<std::is_same<void, typename Worker::ReturnType>::value, void>::type parseJson(std::string const &fileName, Worker &worker, Encoding const encoding = utf8) {
    parseJsonFile(fileName, worker, encoding);
}

template<typename Worker> typename std::enable_if<!std::is_same<void, typename Worker::ReturnType>::value, typename Worker::ReturnType>::type parseJson(std::string const &fileName, Encoding const encoding = utf8) {
    return parseJson(fileName, Worker{}, encoding);
}

template<typename Worker> typename std::enable_if<std::is_same<void, typename Worker::ReturnType>::value, void>::type parseJson(std::string const &fileName, Encoding const encoding = utf8) {
    parseJson(fileName, Worker{}, encoding);
}

#endif
