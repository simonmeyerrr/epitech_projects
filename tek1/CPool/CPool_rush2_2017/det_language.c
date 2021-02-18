/*
** EPITECH PROJECT, 2017
** What is this language?
** File description:
** determine the language of a text
*/

int final_result(int *score, int test)
{
	if (score[0] < score[1] && score[0] < score[2] && score[0] < score[3])
		write(1, "=> English", 10);
	if (score[1] < score[0] && score[1] < score[2] && score[1] < score[3])
		write(1, "=> French", 9);
	if (score[2] < score[0] && score[2] < score[1] && score[2] < score[3])
		write(1, "=> German", 9);
	if (score[3] < score[0] && score[3] < score[1] && score[3] < score[2])
		write(1, "=> Spanish", 10);
	return (0);
}

int compare_pc(char l, int pc, int *score)
{
	for (int i = 0 ; i < 4 ; i++) {
		if (pc >= tab(l, i))
			score[i] = score[i] + ((pc - tab(l, i)) / tab(l, i));
		else
			score[i] = score[i] - ((pc - tab(l, i)) / tab(l, i));
	}
	return (0);
}

int fulloccur(char const *str, char c)
{
	int occur = 0;

	for (int i = 0 ; str[i] != '\0' ; i++) {
		if (str[i] == c + 65 || str[i] == c + 97)
			occur++;
	}
	return (occur);
}

int det_language(char const *str, int letters)
{
	int occur;
	int score[4] = {0, 0, 0, 0};
	int pc;

	for (int l = 0; l < 26 ; l++) {
		occur = fulloccur(str, l);
		pc = occur * 10000 / letters;
		compare_pc(l, pc, &score);
	}
	final_result(&score, 0);
	return (0);
}
