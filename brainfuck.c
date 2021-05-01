#include <stdio.h>
#include <string.h>

int main()
{
	FILE *writer, *reader;
	char readerfile[25], writerfile[25];
	scanf("%s", readerfile);
	int i = -1;
	while(readerfile[++i] != '.')
		writerfile[i] = readerfile[i];
	writerfile[i] = '\0';
	strcat(writerfile, ".c");
	printf("%s", writerfile);
	reader = fopen(readerfile, "r");
	writer = fopen(writerfile, "w");
	fprintf(writer, "%s", "#include <stdio.h>\n\nint main()\n{\nint a[30000] = {0};\nint *ptr = &a[0];");	
	char c;
	while((c = getc(reader)) != EOF)
	{
		char str[25];
		switch(c)
		{
			case '>': strcpy(str, "\n++ptr;"); 	break;
			case '<': strcpy(str, "\n--ptr;"); 	break;
			case '+': strcpy(str, "\n++*ptr;"); break;
			case '-': strcpy(str, "\n--*ptr;");	break;
			case '[': strcpy(str, "\nwhile(*ptr)\n{"); 	break;
			case ']': strcpy(str, "\n}"); 		break;
			case ',': strcpy(str, "\nscanf(\"%c\", ptr);"); break;
			case '.': strcpy(str, "\nprintf(\"%c\", *ptr);"); break;
			default: continue;
		}
		fprintf(writer, "%s", str);
	}
	fprintf(writer, "%s", "\n}");	
	fclose(writer);
	fclose(reader);
	return 0;
}
