/*
** EPITECH PROJECT, 2017
** what is this language?
** File description:
** find the language of a string
*/

void disp_infos(char c, int occur, int pcint, int pcfloat)
{
	int decimal;

	write(1, &c, 1);
	write(1, ":", 1);
	dispnbr(occur);
	write(1, " (", 2);
	dispnbr(pcint);
	write(1, ".", 1);
	decimal = pcfloat - (pcint * 100);
	if (decimal < 10)
		write(1, "0", 1);
	dispnbr(decimal);
	write(1, "%)\n", 3);
}

int count_occur(char const *str, char c, int letters)
{
	char c2;
	int occur = 0;
	int pcint;
	int pcfloat;

	if (char_low(c) == 1)
		c2 = c - 32;
	else if (char_up(c) == 1)
		c2 = c + 32;
	for (int i = 0 ; str[i] != 0 ; i++) {
		if (str[i] == c || str[i] == c2)
			occur++;
	}
	pcint = occur * 100 / letters;
	pcfloat = occur * 10000 / letters;
	disp_infos(c, occur, pcint, pcfloat);
	return (0);
}

int algolanguage(int ac, char **argv, int letters)
{
	for (int i = 2 ; i < ac ; i++) {
		if (argv[i][1] != '\0' || char_letter(argv[i][0]) == 0) {
			write(2, "Invalid argument\n", 17);
			return (84);
		}
		count_occur(argv[1], argv[i][0], letters);
	}
	det_language(argv[1], letters);
	return (0);
}

int main(int argc, char **argv)
{
	int letters;

	if (argc < 2) {
		write(2, "Not enough arguments\n", 21);
		return (84);
	}
	letters = nbrletters(argv[1]);
	if (letters == 0) {
		write(2, "There are,'t any letters\n", 25);
		return (84);
	}
	if (algolanguage(argc, argv, letters) == 84)
		return (84);
	else
		return (0);
}
