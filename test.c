#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	char c;
	char buf[4096];
	struct termios term;
    
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~ICANON;    // non-canonical input 설정
	term.c_lflag &= ~ECHO;      // 입력 시 터미널에 보이지 않게
	term.c_cc[VMIN] = 1;        // 최소 입력 버퍼 크기
	term.c_cc[VTIME] = 0;       //버퍼 비우는 시간 (timeout)
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	int i;
	char *str = strdup("hi");
    while (1)
	{
		memset(buf, 0, 4096);
		i = 0;
		while (read(0, &c, sizeof(c)) > 0)
		{
			// if (i == 5)
			// 	strcpy(buf, str);
			if (c == '\n')
				break ;
			// printf("input: %c\n", c);
			printf("%d\n",c);
			buf[i] = c;
			c = 0;
			i++;;
		}
		printf("%s\n",buf);
	}
    return (0);
}