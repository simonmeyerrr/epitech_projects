#ifndef JSONVISITOR_HPP_
#define JSONVISITOR_HPP_

#include "Types.hpp"

template<typename Worker> struct JsonVisitor {

    explicit JsonVisitor() noexcept : _worker{&_storage}, _rec{false} {
	_worker->begin();
    }

    explicit JsonVisitor(Worker &&worker) noexcept : _storage{std::move(worker)}, _worker{&_storage}, _rec{false} {
	_worker->begin();
    }

    explicit JsonVisitor(Worker &worker, bool const rec = false) noexcept : _worker{&worker}, _rec{rec} {
	if (!_rec)
	    _worker->begin();
    }

    ~JsonVisitor() noexcept {
	if (!_rec)
	    _worker->end();
    }
    
    void operator()(api::JsonNull null) {
	_worker->null();
    }

    void operator()(api::JsonString &str) {
	_worker->string(str);
    }

    void operator()(api::JsonNumber &nb) {
	_worker->number(nb);
    }
    
    void operator()(api::JsonBool b) {
	_worker->boolean(b);
    }
    
    void operator()(api::JsonArray &array) {
	_worker->openArray();
	for (api::JsonArray::iterator b = array.begin(), e = array.end(); e != b;) {
	    visitJson(*b, *_worker, true);
	    if (e != ++b)
		_worker->arraySeparator();
	}
	_worker->closeArray();
    }

    void operator()(api::JsonObject &object) {
	_worker->openObject();
	for (api::JsonObject::iterator b = object.begin(), e = object.end(); e != b;) {
	    _worker->string(b->first);
	    _worker->pair();
	    visitJson(b->second, *_worker, true);
	    if (e != ++b)
		_worker->objectSeparator();
	}	
	_worker->closeObject();
    }

    Worker _storage, *_worker;
    bool const _rec;
};

template<typename Worker> typename std::enable_if<!std::is_same<void, typename Worker::ReturnType>::value, typename Worker::ReturnType>::type visitJson(api::JsonType &json) {
    Worker worker{}; 
    std::visit(JsonVisitor{worker}, json._);
    return worker();
}

template<typename Worker> typename std::enable_if<std::is_same<void, typename Worker::ReturnType>::value, void>::type visitJson(api::JsonType &json) {
    std::visit(JsonVisitor<Worker>{}, json._);
}

template<typename Worker> typename std::enable_if<!std::is_same<void, typename Worker::ReturnType>::value, typename Worker::ReturnType>::type visitJson(api::JsonType &&json) {
    Worker worker{};
    std::visit(JsonVisitor{worker}, json._);
    return worker();
}

template<typename Worker> typename std::enable_if<std::is_same<void, typename Worker::ReturnType>::value, void>::type visitJson(api::JsonType &&json) {
    std::visit(JsonVisitor<Worker>{}, json._);
}

template<typename Worker> typename std::enable_if<!std::is_same<void, typename Worker::ReturnType>::value, typename Worker::ReturnType>::type visitJson(api::JsonType &json, Worker &worker, bool const rec = false) {
    std::visit(JsonVisitor{worker, rec}, json._);
    return worker();
}

template<typename Worker> typename std::enable_if<std::is_same<void, typename Worker::ReturnType>::value, void>::type visitJson(api::JsonType &json, Worker &worker, bool const &rec = false) {
    std::visit(JsonVisitor{worker, rec}, json._);
}

template<typename Worker> typename std::enable_if<!std::is_same<void, typename Worker::ReturnType>::value, typename Worker::ReturnType>::type visitJson(api::JsonType &&json, Worker &worker, bool const &rec = false) {
    std::visit(JsonVisitor{worker, rec}, json._);
    return worker();
}

template<typename Worker> typename std::enable_if<std::is_same<void, typename Worker::ReturnType>::value, void>::type visitJson(api::JsonType &&json, Worker &worker, bool const &rec = false) {
    std::visit(JsonVisitor{worker, rec}, json._);
}

template<typename Worker> typename std::enable_if<!std::is_same<void, typename Worker::ReturnType>::value, typename Worker::ReturnType>::type visitJson(api::JsonType &json, Worker &&worker) {
    std::visit(JsonVisitor{worker}, json._);
    return worker();
}

template<typename Worker> typename std::enable_if<std::is_same<void, typename Worker::ReturnType>::value, void>::type visitJson(api::JsonType &json, Worker &&worker) {
    std::visit(JsonVisitor{worker}, json._);
}

template<typename Worker> typename std::enable_if<!std::is_same<void, typename Worker::ReturnType>::value, typename Worker::ReturnType>::type visitJson(api::JsonType &&json, Worker &&worker) {
    std::visit(JsonVisitor{worker}, json._);
    return worker();
}

template<typename Worker> typename std::enable_if<std::is_same<void, typename Worker::ReturnType>::value, void>::type visitJson(api::JsonType &&json, Worker &&worker) {
    std::visit(JsonVisitor{worker}, json._);
}

#endif
