#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
	char pwd_table[26][26], key[21] = { 0 }, name[21] = { 0 };
	int alphabet, i, j, ch;

	for (i = 0; i < 26; i++) {		//储存密码表
		for (j = 0; j < 26; j++) {
			alphabet = 'a' + i + j;
			while (alphabet > 'z')
				alphabet = alphabet - 'z' + 'a' - 1;
			pwd_table[i][j] = alphabet;
		}
	}

	printf("请输入你的秘钥：");
	for (i = 0; (ch = getchar()) != EOF; i++) {
		if (ch == '\n')
			break;
		key[i] = tolower(ch);
	}

	printf("请输入你的名字进行加密：");
	for (j = 0; (ch = getchar()) != EOF; j++) {
		if (ch == '\n')
			break;
		name[j] = tolower(ch);
	}

	for (i = 0, j = 0; j < strlen(name); i++, j++) {
		if (i == strlen(key))
			i -= strlen(key);
		
		printf("%c", pwd_table[key[i]- 'a'][name[j] - 'a']);
	}

	return 0;
}