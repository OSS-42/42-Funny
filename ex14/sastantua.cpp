#include <iostream>

int doorSizer(int size) {
	return (size - 1 + size % 2);
}

int calc_width(int nb) {
	int segLines;
	int i;
	int width;

	width = 7;
	i = 2;
	segLines = 4;
	while (i <= nb)
	{
		width += (((i - 2) / 2) + 3) * 2 - 2;
		while (segLines >= 1)
		{
			width += 2;
			--segLines;
		}
		segLines = i + 3;
		++i;
	}
	return (width);
}

void line_printer(int totalWidth, int w) {
	int i;

	i = 1;
	while (i <= (totalWidth - w) / 2 + w)
	{
		if (i <= ((totalWidth / 2) - (w / 2))) {
			std::cout << ' ';
		} else if (i == ((totalWidth - w) / 2) + 1) {
			std::cout << '/';
		} else if (i == (totalWidth - w) / 2 + w) {
			std::cout << '\\';
		} else {
			std::cout << '*';
		}
		++i;
	}
	std::cout << '\n';
}

void line_printer_door(int totalWidth, int w, int doorKnob, int doorSize) {
	int i;

	i = 1;
	while (i <= (totalWidth - w) / 2 + w)
	{
		if (i <= ((totalWidth / 2) - (w / 2)))
			std::cout << ' ';
		else if (i == ((totalWidth - w) / 2) + 1)
			std::cout << '/';
		else if (i == (totalWidth - w) / 2 + w)
			std::cout << '\\';
		else if (doorKnob && i == w / 2 + doorSize - 1)
			std::cout << '$';
		else if (i > totalWidth / 2 + 1 - doorSize / 2 - 1 && i < totalWidth / 2 + doorSize / 2 + 2)
			std::cout << '|';
		else
			std::cout << '*';
		++i;
	}
	std::cout << '\n';
}

void generatePyramid(int size) {
	int line;
	int segment;
	int totalWidth;
	int doorSize;

	doorSize = doorSizer(size);
	totalWidth = calc_width(size);
	line = 1;
	segment = 1;
	while (segment <= size) {
		while (line <= segment + 2) {
			if (segment == size && line > 3 - segment % 2) {
				if (line == segment + 2 - doorSize / 2 && size > 4)
					line_printer_door(totalWidth, (calc_width(segment) - 2 * (segment + 2 - line)), 1, doorSize);
				else
					line_printer_door(totalWidth, (calc_width(segment) - 2 * (segment + 2 - line)), 0, doorSize);
			}
			else
				line_printer(totalWidth, (calc_width(segment) - 2 * (segment + 2 - line)));
			++line;
		}
		line = 1;
		++segment;
	}
}

int main(int ac,  char **av) {
	if (ac != 2 || !av[1] || std::atoi(av[1]) <= 0) {
		std::cout << "wrong parameters. Retry." << std::endl;
		return 0;
	}
	for (int i = 0; i < std::strlen(av[1]); i++) {
		if (std::isdigit(av[1][i]) == 0) {
			std::cout << "Numbers only. Retry" << std::endl;
			return 0;
		}
	}
	
	int n;

	n = std::atoi(av[1]);
	generatePyramid(n);
	return 0;
}