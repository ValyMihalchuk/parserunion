#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char* concat(char *s1, char *s2) {

	size_t len1 = strlen(s1);
	size_t len2 = strlen(s2);

	char *result = malloc(len1 + len2 + 1);

	if (!result) {
		fprintf(stderr, "malloc() failed: insufficient memory!\n");
		return NULL;
	}

	memcpy(result, s1, len1);
	memcpy(result + len1, s2, len2 + 1);

	return result;
}

char* parsinf(FILE *file, float time1, float time2)
{
	float t1, t2;
	char *str = malloc(5000);
	char *result = malloc(5000);
	result[0] = ' ';
	result[1] = 0;


	while (fscanf(file, "%f/%s", &t1, str) != EOF) {
		int i = 0;
		while (str[i] < -1 || str[i]>255 || !isdigit(str[i]))
			i++;
		char *newstr = malloc(5000);
		int j = 0;
		str[i - 1] = 0;
		while (str[i])
		{
			newstr[j] = str[i];
			j++;
			i++;
		}
		newstr[j] = 0;
		t2 = atof(newstr);

		if (t1 >= time1 && t2 <= time2)
		{
		;
			result = concat(result, " ");
			result = concat(result, str);
		}
		
	
	}

	return result;
}
void main() {


	FILE *file, *file1;

	file = fopen("C:/test/dial.txt", "r");
	float t1, t2;
	char *str = malloc(5000);


	file1 = fopen("C:/test/8.lab", "r");
	float time1 =0, time2=0;
	int speaker = 0;
	while (fscanf(file1, "%f %f speech", &time1, &time2) != EOF) {

-		printf("(Speaker %i) : <%f> %s <%f>\n", speaker, time1, parsinf(file, time1, time2), time2);
		speaker = (speaker + 1) % 2;
		time1 = 0;
		time2 = 0;
		fseek(file, 0, SEEK_SET);
	}



	getchar();
}
