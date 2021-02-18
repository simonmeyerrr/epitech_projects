/*
** EPITECH PROJECT, 2017
** tab.c
** File description:
** define tab language
*/

int tab(char c, int country)
{
	int result;

	if (country == 0)
		result = english(c);
	if (country == 1)
		result = french(c);
	if (country == 2)
		result = german(c);
	if (country == 3)
		result = spanish(c);
	return (result);
}

int english(int c)
{
	int english[26] = {816, 149, 278, 425, 1270, 222, 201, 609,
			   696, 15, 77, 402, 240, 674, 750, 192, 9,
			   598, 632, 905, 275, 97, 236, 15, 197, 7};
	return (english[c]);
}

int french(int c)
{
	int french[26] = {763, 90, 326, 366, 1471, 106, 86, 73, 752,
			  61, 4, 545, 296, 709, 579, 252, 136, 669,
			  794, 724, 631, 183, 7, 42, 12, 32};
	return (french[c]);
}

int german(int c)
{
	int german[26] = {651, 188, 273, 507, 1639, 165, 300, 457,
			  655, 26, 141, 343, 253, 977, 259, 67, 1,
			  700, 727, 615, 416, 84, 192, 3, 3, 113};
	return (german[c]);
}

int spanish(int c)
{
	int spanish[26] =  {1152, 221, 401, 501, 1218, 69, 176, 70,
			    624, 49, 1, 496, 315, 671, 868, 251, 87,
			    687, 797, 463, 292, 113, 1, 21, 100, 46};
	return (spanish[c]);
}
