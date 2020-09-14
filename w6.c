/*
題目敘述

寫一個程式將輸入做縮寫處理。比如說 "national"、"taiwan"、"university" 這三個字串的話，縮寫就是 "NTU"。注意，有四種字串必須直接省略，不納入縮寫中："of"、 "and"、"the" 以及 "at"。例如 "the"、"united"、"states"、"of"、"amarica" 將會被縮寫成 "USA"。

輸入格式

輸入會是一連串的小寫詞彙以及句號 (period '.')。要縮寫在一起的詞彙中，最後一個詞的結尾將會有一個句號。以前面舉的"NTU"為例，程式收到的輸入會是 "national"、"taiwan" 以及 "university."。注意有一個句號在字串 "university." 的結尾。你的程式將會一直讀入輸入直到 EOF。我們保證輸入的最後一個詞彙的結尾一定會有句號；"of"、"and"、"the" 以及 "at" 不會是各個縮寫的最後一個詞彙，意即不會有 "of." 這樣的字串出現。我們也保證每個縮寫至少都會有一個字元。

輸出格式

你的程式必須在一行 (single line)內輸出所有的縮寫。(縮寫間留一個空白)


輸入限制

一個字彙(包含句號)的長度不會超過 127 個字元。一個縮寫的長度將不會超過 127 個字元。

輸入範例

the united states of america. taiwan high speed rail. national aeronautics
and space administration. metropolitan rapid transit. north atlantic treaty
organization. european union. university of hong kong. national chiao tong
university. massachusetts institute of technology. united kingdom. national
taiwan university. university of california at san diego. immigration and
naturalization service.

輸出範例

USA THSR NASA MRT NATO EU UHK NCTU MIT UK NTU UCSD INS
*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char const *argv[])
{
	char backronym[128];
	char skip[4][4] = {"of", "and", "the", "at"};

	while (scanf("%s", backronym) != EOF) {
		int flag = 0;

		for (int i = 0; i < 4; ++i) {
			if (!strcmp(backronym, skip[i])) { //returns 0 if backronym == skip[i]
				flag = 1;
				break;
			}
		}

		if (flag)
			continue;

		printf("%c", toupper(backronym[0]));

		if (strchr(backronym, '.') != NULL) //returns NULL if '.' doesn't exist
			printf(" ");
	}

	return 0;
}