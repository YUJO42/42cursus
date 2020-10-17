#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

int		ft_strlen(char *str)
{
	int		count;

	count = 0;
	while (*str++)
		count++;
	return (count);
}

int		ft_error(char *str)
{
	write(1, str, ft_strlen(str));
	return (1);
}

int		is_shape(float x_axis, float y_axis, float x, float y, float width, float height)
{
	// 도형에 관해서 경계와 안쪽을 구하는 식은 !!
	// 포함시키지 않았습니다.
	// exam시험에서 구하는 공식이 주어지는데!
	// 그래픽스 minilibx를 사용해봤다면 가능!
	;
}

int main(int argc, char *argv[])
{
	FILE	*file;
	char	*image;
	int		read;
	int		w_width; //창의 넓이
	int		w_height; //창의 높이
	char	w_background; //배경색
	int		x_axis;
	int		y_axis;
	int		paint;

	char	type;
	float	x;
	float	y;
	float	width;
	float	height;
	char	color;

	if (argc != 2) //매개 변수가 잘못되었을때 !
		return (ft_error("Error: argument\n"));
	if (!(file = fopen(argv[1], "r"))) // open 실패시 널을 반환해서 널이면 오류!
		return (ft_error("Error: Operation file corrupted\n"));
	if (fscanf(file, "%d %d %c\n", &w_width, &w_height, &w_background) != 3) //fscanf에 \n을 주는 이유는 한줄씩 스캔하는데 한줄에서 마지막 개해을 버리기 위해서!
		return (ft_error("Error: Operation file corrupted\n"));
	if (w_width <= 0 || w_width > 300 || w_height <= 0 || w_height > 300)
		return (ft_error("Error: Operation file corrupted\n"));
	image = (char *)malloc(sizeof(char) * (w_width * w_height)); //메모리 할당이 힙영역의 크기보다 못 미치는 샘플이라 가드 안함
	memset(image, w_background, w_width * w_height); //맴셋을 통해 바탕색을 칠합니다.
	read = fscanf(file, "%c %f %f %f %f %c\n", &type, &x, &y, &width, &height, &color);
	while (read == 6)
	{
		if (width <= 0 || height <= 0 || (type != 'R' && type != 'r'))
		{
			free(image);
			return (ft_error("Error: Operation file corrupted\n"));
		}
		y_axis = 0;
		while (y_axis < w_height)
		{
			x_axis = 0;
			while (x_axis < w_width)
			{
				//어떠한 도형의 문제가 나오더라도 워크로드는 같고
				// paint에 결과값을 받아서 아래에서 처리해주면 됩니당.
				// paint = is_shape(x_axis, y_axis, x, y, width, height); 현재의 x,y축과 중심점 그리고 그외 것들을 보내서! 결과값 만들기
				if ((type == 'r' && paint == 1) || (type == 'R' && paint)) // 경계인 도형은 경계조건이 만족했을대 내부까지 색칠하는건 유효하면 색칠!
					image[y_axis * w_width + x_axis] = color; //y축이 증가하면 창의 크기를 곱해서 위치조정
				x_axis++;
			}
			y_axis++;
		}
		read = fscanf(file, "%c %f %f %f %f %c\n", &type, &x, &y, &width, &height, &color); // 파일이 끝날때까지 반복해서 읽어야 됨.
	}
	if (read != -1) //while 정상 탈출 조건이 EOF이기 때문에
	{
		free(image);
		return (ft_error("Error: Operation file corrupted\n"));
	}
	y_axis = 0; // 출력을 위해 y축 초기화
	while (y_axis < w_height)
	{
		write(1, image + y_axis * w_width, w_width); //1줄씩 출력하기 위해서
		write(1, "\n", 1); //한줄 출력하고 개행
		y_axis++;
	}
	free(image); // 메모리누수는 발생하면 안되니까! 메모리가 해제되어 야 할 상황에선 꼭 프리해주었습니다.
	fclose(file); // 사실 위에 에러상황에서 파일을 명시적으로 닫아줘야하는데 프로그램이 종료되면 닫힌다고해서 꼼꼼하게 처리하진 않았습니다.
	return (0);
}
