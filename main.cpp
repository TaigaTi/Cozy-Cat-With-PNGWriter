#pragma warning(disable: 4996)
#pragma comment(lib, "shell32.lib")

#define _CRT_SECURE_NO_WARNINGS
#include "pngwriter.h" 
#include <string>

/* 
	Name: Tarika Birch
	ID: 400013038
	Theme: Cozy Kitty
	
	Functions Used:
	1.  square
	2.  filledsquare
	3.  filledsquare_blend
	4.  triangle
	5.  filledtriangle
	6.  filledtriangle_blend
	7.  circle
	8.  circle_blend
	9.  filledcircle
	10. filledcircle_blend
	11. diamond
	12. filleddiamond
	13. arrow
	14. filledarrow
	15. maltesecross
	16. polygon
	17. polygon_blend
	18. flood_fill
	19. flood_fill_blend
	20. line
	21. boundary_fill
	22. cross
	23. read
	24. dread
	25. dreadHSV
	26. bezier
	27. setgamma
	28. plot_blend
	29. plotHSV
	30. line_blend
	31. getwidth
	32. getheight
	33. getgamma
	34. getbitdepth
	35. getcolortype
	36. settext
*/

int main()
{
	int width = 750;
	int height = 1000;

	pngwriter image(width, height, 1.0, "cat.png");

	// Image Details
	char title[] = "Cozy Kitty";
	char author[] = "Tarika Birch";
	char description[] = "Cozy kitty on a cozy night!";
	char software[] = "PNGWriter";
	image.settext(title, author, description, software);

	// Wall & Window Frame
	image.filledsquare(0, 0, width, height, 0.5216, 0.3843, 0.3059); // Wall
	image.filledsquare(160, 360, 590, 890, 0.4392, 0.3059, 0.2314); // Window Frame

	// Sky
	image.filledsquare(200, 400, 550, 850 , 0.6314, 0.4039, 0.6); // Sky
	image.filledcircle(225, 840, 40, 1.0, 1.0, 1.0); // Moon

	for (int i = 0; i < 10; i++) {
		image.circle_blend(225, 840, 40 + i, 1 - i / static_cast<double>(10), 1.0, 1.0, 1.0);
		image.filledcircle_blend(225, 840, 40 + i + 1, 1 - i / static_cast<double>(10), 1.0, 1.0, 1.0);
	};

	// Stars
	image.filleddiamond(290, 500, 7, 11, 1.0, 1.0, 1.0);
	image.filleddiamond(500, 470, 11, 16, 1.0, 1.0, 1.0);
	image.filleddiamond(520, 490, 6, 10, 1.0, 1.0, 1.0);
	image.filleddiamond(525, 625, 10, 15, 1.0, 1.0, 1.0);
	image.filleddiamond(500, 810, 9, 12, 1.0, 1.0, 1.0);
	image.filleddiamond(300, 800, 9, 14, 1.0, 1.0, 1.0);
	image.diamond(250, 625, 9, 14, 1.0, 1.0, 1.0);
	image.boundary_fill(250, 625, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0);

	// Window Bars
	image.filledsquare(160, 850, 590, 890, 0.4392, 0.3059, 0.2314); // Top Window Frame
	image.filledsquare(160, 360, 200, 890, 0.4392, 0.3059, 0.2314); // Left Window Frame
	image.filledsquare(160, 680, 590, 710, 0.4392, 0.3059, 0.2314); // Second Horizontal Window Bar
	image.filledsquare(160, 525, 590, 555, 0.4392, 0.3059, 0.2314); // Third Horizontal Window Bar
	image.filledsquare(360, 360, 390, 890, 0.4392, 0.3059, 0.2314); // Vertical Window Bar
	
	int shelf_top = 115;

	// Plants
	// Left Plant Pot
	image.line(80, 410, 100, 550, 0.6745, 0.5059, 0.4118);
	image.line(0, 550, 100, 550, 0.6745, 0.5059, 0.4118);
	image.line(0, 410, 80, 410, 0.6745, 0.5059, 0.4118);
	image.flood_fill(25, 450, 0.675, 0.506, 0.412);
	image.line_blend(0, 520, 97, 520, 0.35, 0.4392, 0.3059, 0.2314);

	// Left Plant Leaves
	image.filledtriangle_blend(0, 825, 30, 550, 0, 550, 0.9, 0.459, 0.741, 0.545);
	image.filledtriangle_blend(-100, 550, 85, width, 30, 550, 0.9, 0.459, 0.741, 0.545);
	image.filledtriangle_blend(-25, 550, 110, 650, 65, 550, 0.9, 0.459, 0.741, 0.545);

	// Right Plant Pot
	image.line(650, 550, 675, 410, 0.6745, 0.5059, 0.4118);
	image.line(650, 550, width, 550, 0.6745, 0.5059, 0.4118);
	image.line(650, 410, width, 410, 0.6745, 0.5059, 0.4118);
	image.flood_fill(700, 450, 0.675, 0.506, 0.412);    

	double potLineHue = image.dreadHSV(10, 520, 1);
	double potLineSat = image.dreadHSV(10, 520, 2);
	double potLineVal = image.dreadHSV(10, 520, 3);

	for (int i = 655; i <= width; i++) {
		image.plotHSV(i, 520, potLineHue, potLineSat, potLineVal);
	}

	// Right Plant Leaves
	image.filledtriangle_blend(680, 550, 630, 680, width, 550, 0.9, 0.459, 0.741, 0.545);
	image.filledtriangle_blend(690, 550, 675, 760, 800, 550, 0.9, 0.459, 0.741, 0.545);
	image.filledtriangle_blend(720, 550, width, 800, 780, 550, 0.9, 0.459, 0.741, 0.545);


	// Book Shelf
	image.filledsquare(0, 0, width, 410, 0.7765, 0.6196, 0.5137); // Top
	image.filledsquare(0, 0, width, 325, 0.6745, 0.5059, 0.4118); // Edge
	image.filledsquare(0, 0, width, 300, 0.4392, 0.3059, 0.2314); // Back
	image.filledsquare(0, 100, width, shelf_top, 0.6745, 0.5059, 0.4118); // Shelf


	// Top Shelf Books (Ordered Left to Right)
	// Red Book 
	image.filledsquare(0, shelf_top, 110, 280, 0.5294, 0.2510, 0.2863);
	image.maltesecross(50, 202, 50, 75, 25, 25, 0.7569, 0.5373, 0.5569);

	// Yellow Book
	image.filledsquare(110, shelf_top, 160, 250, 0.9137, 0.7176, 0.4980);
	image.filledsquare(110, 135, 160, 147, 0.8667, 0.5961, 0.4431);
	image.square(110, 217, 160, 230, 0.8667, 0.5961, 0.4431);
	image.flood_fill(125, 220, 0.8667, 0.5961, 0.4431);

	// Orange Book
	image.filledsquare(160, shelf_top, 219, 285, 0.8039, 0.4431, 0.3804);
	image.filleddiamond(190, 235, 25, 35, 0.9451, 0.8196, 0.6706);
	image.filledcircle(190, 200, 6, 0.9451, 0.8196, 0.6706);

	// Green Book
	int green_book_xcenter = 260;

	image.filledsquare(220, shelf_top, 300, 260, 0.5451, 0.6392, 0.5569);
	image.filledsquare(220, 235, 300, green_book_xcenter, 0.3922, 0.5451, 0.4980);
	image.filledcircle(green_book_xcenter - 8, 160, 9, 0.3922, 0.5451, 0.4980);
	image.filledcircle(green_book_xcenter + 8, 160, 9, 0.3922, 0.5451, 0.4980);
	image.filledtriangle(green_book_xcenter, 142, green_book_xcenter - 15, 155, green_book_xcenter + 15, 155, 0.3922, 0.5451, 0.4980);

	// Purple Book
	image.filledsquare(300, shelf_top, 385, 282, 0.5176, 0.3569, 0.6039);
	image.filleddiamond(342, 230, 30, 40, 0.7529, 0.6667, 0.8353);
	image.filleddiamond(342, 185, 20, 25, 0.7529, 0.6667, 0.8353);

	// Blue Book
	image.filledsquare(385, shelf_top, 440, 260, 0.2392, 0.2824, 0.5137);
	image.filledarrow(412, 175, 412, 225, 20, 50, 0.5176, 0.5451, 0.7098);

	// Light Blue Book
	image.filledsquare(440, shelf_top, 499, 272, 0.4824, 0.5451, 0.5725);
	image.filledcircle(470, 237, 12, 0.70196, 0.7451, 0.7647);

	double diagonalCrossValue  = 1.0;
	int diagonalCrossPosition[2] = { 470, 237 };

	for (int i = 0; i < 5; i++) {
		image.plot_blend(diagonalCrossPosition[0] + i, diagonalCrossPosition[1] + i, 0.4, diagonalCrossValue, diagonalCrossValue, diagonalCrossValue);
		image.plot_blend(diagonalCrossPosition[0] - i, diagonalCrossPosition[1] + i, 0.4, diagonalCrossValue, diagonalCrossValue, diagonalCrossValue);
	}
	for (int i = 0; i < 5; i++) {
		image.plot_blend(diagonalCrossPosition[0] - i, diagonalCrossPosition[1] - i, 0.4, diagonalCrossValue, diagonalCrossValue, diagonalCrossValue);
		image.plot_blend(diagonalCrossPosition[0] + i, diagonalCrossPosition[1] - i, 0.4, diagonalCrossValue, diagonalCrossValue, diagonalCrossValue);
	}

	// Navy Blue Book
	image.filledsquare(500, shelf_top, 575, 250, 0.1451, 0.2784, 0.4039);
	image.filleddiamond(537, 195, 35, 40, 0.5725, 0.6392, 0.6706);

	// Red Book
	image.filledsquare(575, shelf_top, 625, 230, 0.5294, 0.2510, 0.2863);
	image.filledarrow(600, 200, 600, 150, 20, 50, 0.7647, 0.5412, 0.5608);

	// Yellow Book
	const int num_book_polygon_points = 5;
	int yellow_book_polygon_points[num_book_polygon_points * 2] = { 625, 275, 645, 250, 675, 250, 695, 275, 625, 275 };

	image.filledsquare(625, shelf_top, 695, 275, 0.8667, 0.6275, 0.4275);
	image.polygon(yellow_book_polygon_points, num_book_polygon_points, 0.922, 0.780, 0.584);
	image.flood_fill(675, 260, 0.922, 0.780, 0.584);
	image.arrow(660, 230, 660, 140, 20, 80, 0.922, 0.780, 0.584);

	// Pink Book
	image.filledsquare(695, shelf_top, width, 300, 0.8235, 0.5098, 0.6980);


	// Bottom Shelf (Right to Left)
	// Orange Book
	image.filledsquare(675, 0, width, 50, 0.8039, 0.4431, 0.3804);
	image.maltesecross(712, 15, 25, 35, 15, 15, 0.9451, 0.8196, 0.6706);

	// Purple Book
	image.filledsquare(600, 0, 675, 85, 0.5176, 0.3569, 0.6039);
	image.filledcircle(637, 50, 12, 0.7529, 0.6667, 0.8353);
	image.circle(637, 20, 7, 0.7529, 0.6667, 0.8353);
	image.flood_fill(637, 20, 0.7529, 0.6667, 0.8353);

	// Yellow Book
	image.filledsquare(525, 0, 600, 62, 0.9137, 0.7176, 0.4980);
	image.filledsquare_blend(525, 40, 600, 62, 0.3, 0.8039, 0.4431, 0.3804);

	// Pink Book
	image.filledsquare(465, 0, 525, 45, 0.8235, 0.5098, 0.6980);
	image.filledcircle_blend(495, 7, 15, 0.3, 1.0, 1.0, 1.0);
	
	int pinkRed = image.read(495,7, 1);
	int pinkGreen = image.read(495, 7, 2);
	int pinkBlue = image.read(495, 7, 3);
	int pinkRGBValues[3] = { pinkRed, pinkGreen, pinkBlue };
	image.cross(722, 207 + 20, 30, 50, pinkRed, pinkGreen, pinkBlue);
	image.cross(722, 207 - 20, 30, 50, pinkRed, pinkGreen, pinkBlue);

	// Plant
	image.filledtriangle(430, 0, 430, 60, 390, 0, 0.459, 0.741, 0.545);
	image.filledtriangle(375, 0, 355, 85, 330, 0, 0.459, 0.741, 0.545);
	image.filledtriangle(320, 0, 270, 70, 270, 0, 0.459, 0.741, 0.545);

	// Frame
	image.filledsquare(50, 0, 200, 60, 0.816, 0.580, 0.471);
	image.filledsquare(65, 0, 185, 45, 0.627, 0.784, 0.882);

	const int num_frame_polygon_points = 5;
	int frame_polygon_points[num_frame_polygon_points * 2] = { 200, 0, 200, 60, 220, 45, 220, 0, 200, 0 };

	image.polygon_blend(frame_polygon_points, num_frame_polygon_points, 0.9, 0.659, 0.384, 0.345);
	image.flood_fill_blend(210, 20, 0.9, 0.659, 0.384, 0.345);

	// Framed Image
	image.filledtriangle(82, 0, 107, 32, 132, 0, 0.3922, 0.5451, 0.4980);
	image.triangle(132, 0, 147, 12, 162, 0, 0.3922, 0.5451, 0.4980);
	image.flood_fill(140, 1, 0.3922, 0.5451, 0.4980);
	image.filledcircle(165, 30, 6, 0.9137, 0.7176, 0.4980);


	// Cat
	double catRed = 0.945;
	double catGreen = 0.690;
	double catBlue = 0.471;
	
	// Tail
	image.bezier(350, 650, 350, 850, 450, 780, 450, 820, 0.251, 0.145, 0.110);
	image.bezier(450, 780, 420, 720, 400, 500, 380, 850, 0.251, 0.145, 0.110);
	image.line(350, 650, 400, 500, 0.251, 0.145, 0.110);
	image.flood_fill(380, 780, catRed, catGreen, catBlue);
	image.flood_fill(400, 780, catRed, catGreen, catBlue);
	image.flood_fill(358, 720, catRed, catGreen, catBlue);
	image.flood_fill(355, 670, catRed, catGreen, catBlue);
	image.flood_fill(392, 670, catRed, catGreen, catBlue);
	 
	// Body
	image.filledcircle(375, 500, 150, catRed, catGreen, catBlue);
	image.circle(375, 500, 150, 0.251, 0.145, 0.110);

	// Left Ear
	image.filledtriangle(285, 520, 250, 590, 360, 550, catRed, catGreen, catBlue);
	image.triangle(285, 520, 250, 590, 360, 550, 0.251, 0.145, 0.110);
	image.filledtriangle(300, 520, 270, 570, 350, 540, 0.867, 0.549, 0.475);
	image.triangle(300, 520, 270, 570, 350, 540, 0.251, 0.145, 0.110);

	// Right Ear
	image.filledtriangle(365, 550, 470, 610, 460, 530, catRed, catGreen, catBlue);
	image.triangle(365, 550, 470, 610, 460, 530, 0.251, 0.145, 0.110);
	image.filledtriangle(390, 550, 455, 590, 445, 515, 0.867, 0.549, 0.475);
	image.triangle(390, 550, 455, 590, 445, 515, 0.251, 0.145, 0.110);

	// Head
	image.filledcircle(375, 480, 100, catRed, catGreen, catBlue);
	image.circle(375, 480, 100, 0.251, 0.145, 0.110);

	// Left Paw
	image.filledcircle(300, 380, 35, catRed, catGreen, catBlue);
	image.circle(300, 380, 35, 0.251, 0.145, 0.110);

	// Right Paw
	image.filledcircle(450, 380, 35, catRed, catGreen, catBlue);
	image.circle(450, 380, 35, 0.251, 0.145, 0.110);

	// Nose
	image.filledtriangle(360, 465, 390, 468, 377, 450, 0.251, 0.145, 0.110); 

	// Left Eye
	image.filledcircle(330, 490, 22, 0.251, 0.145, 0.110); // Eyeliner
	image.filledcircle(330, 490, 18, 1.0, 1.0, 1.0); // Eye
	image.filledcircle(332, 488, 17, 0.251, 0.145, 0.110); // Outline
	image.filledcircle(332, 488, 15, 0.459, 0.557, 0.573); // Iris
	image.filledcircle(334, 489, 14, 0.251, 0.145, 0.110); // Pupil
	image.filledcircle(335, 495, 3, 1.0, 1.0, 1.0); // Big Sparkle
	image.filledcircle(328, 489, 2, 1.0, 1.0, 1.0); // Small Sparkle

	// Right Eye
	image.filledcircle(415, 500, 22, 0.251, 0.145, 0.110); // Eyeliner
	image.filledcircle(415, 500, 18, 1.0, 1.0, 1.0); // Eye
	image.filledcircle(413, 498, 17, 0.251, 0.145, 0.110); // Outline
	image.filledcircle(413, 498, 15, 0.459, 0.557, 0.573); // Iris
	image.filledcircle(410, 498, 14, 0.251, 0.145, 0.110); // Pupil
	image.filledcircle(410, 504, 3, 1.0, 1.0, 1.0); // Big Sparkle
	image.filledcircle(404, 497, 2, 1.0, 1.0, 1.0); // Small Sparkle

	// Blush
	image.filledcircle(330, 450, 9, 0.867, 0.549, 0.475); // Left
	image.filledcircle(420, 460, 9, 0.867, 0.549, 0.475); // Right

	double tongueRed = image.dread(420, 460, 1);
	double tongueGreen = image.dread(420, 460, 2);
	double tongueBlue = image.dread(420, 460, 3);

	// Mouth
	image.bezier(377, 450, 385, 430, 400, 445, 400, 445, 0.251, 0.145, 0.110); // Right Curve
	image.bezier(377, 450, 375, 430, 355, 440, 355, 440, 0.251, 0.145, 0.110); // Left Curve
	image.bezier(365, 437, 370, 415, 390, 439, 395, 425, 0.251, 0.145, 0.110); // Tongue Outline
	image.flood_fill(380, 430, tongueRed, tongueGreen, tongueBlue); // Tongue Fill

	image.setgamma(0.55);

	// Assignment Info
	int font_size = 12;
	int line_height = 22;
	int first_line = 960;

	double font_red = 0.9451;
	double font_green = 0.8196;
	double font_blue = 0.6706;

	char font_type_path[] = "C:\\Users\\tarik\\OneDrive\\Documents\\UWI\\Assignment-1\\Montserrat-SemiBold.ttf";
	char name[] = "Tarika Birch";
	char id[] = "400013038";
	char theme[] = "Cozy Kitty";

	image.plot_text(font_type_path, font_size, 50, first_line, 0, name, font_red, font_green, font_blue);
	image.plot_text(font_type_path, font_size, 50, first_line - line_height, 0, id, font_red, font_green, font_blue);
	image.plot_text(font_type_path, font_size, 50, first_line - (line_height * 2), 0, theme, font_red, font_green, font_blue);


	// Image Info
	// Size
	int infoXStart = 600;
	char imageWidthLabel[] = "Size: ";
	std::string imageWidth = std::to_string(image.getwidth());
	char imageWidthCStr[5] = {};

	for (int i = 0; i < imageWidth.length(); i++) {
		imageWidthCStr[i] = imageWidth[i];
	}

	image.plot_text(font_type_path, font_size, infoXStart, first_line, 0, imageWidthLabel, font_red, font_green, font_blue);
	image.plot_text(font_type_path, font_size, infoXStart + 50, first_line, 0, imageWidthCStr, font_red, font_green, font_blue);

	// Height
	char multiplier[] = "x";
	std::string imageHeight = std::to_string(image.getheight());
	char imageHeightCStr[5] = {};

	for (int i = 0; i < imageHeight.length(); i++) {
		imageHeightCStr[i] = imageHeight[i];
	}

	image.plot_text(font_type_path, font_size, infoXStart + 85, first_line, 0, multiplier, font_red, font_green, font_blue);
	image.plot_text(font_type_path, font_size, infoXStart + 100, first_line, 0, imageHeightCStr, font_red, font_green, font_blue);

	// Gamma
	char imageGammaLabel[] = "Gamma: ";
	std::string imageGamma = std::to_string(image.getgamma());
	char imageGammaCStr[10] = {};

	for (int i = 0; i < imageGamma.length() - 4; i++) {
		imageGammaCStr[i] = imageGamma[i];
	}

	image.plot_text(font_type_path, font_size, infoXStart, first_line - line_height, 0, imageGammaLabel, font_red, font_green, font_blue);
	image.plot_text(font_type_path, font_size, infoXStart + 80, first_line - line_height, 0, imageGammaCStr, font_red, font_green, font_blue);

	// Bit Depth
	char imageBitDepthLabel[] = "Bit Depth: ";
	std::string imageBitDepth = std::to_string(image.getbitdepth());
	char imageBitDepthCStr[10] = {};

	for (int i = 0; i < imageBitDepth.length(); i++) {
		imageBitDepthCStr[i] = imageBitDepth[i];
	}

	image.plot_text(font_type_path, font_size, infoXStart, first_line - (line_height * 2), 0, imageBitDepthLabel, font_red, font_green, font_blue);
	image.plot_text(font_type_path, font_size, infoXStart + 100, first_line - (line_height * 2), 0, imageBitDepthCStr, font_red, font_green, font_blue);

	// Color Type
	char imageColorTypeLabel[] = "Color Type: ";
	std::string imageColorType = std::to_string(image.getcolortype());
	char imageColorTypeCStr[10] = {};

	for (int i = 0; i < imageColorType.length(); i++) {
		imageColorTypeCStr[i] = imageColorType[i];
	}

	image.plot_text(font_type_path, font_size, infoXStart, first_line - (line_height * 3), 0, imageColorTypeLabel, font_red, font_green, font_blue);
	image.plot_text(font_type_path, font_size, infoXStart + 105, first_line - (line_height * 3), 0, imageColorTypeCStr, font_red, font_green, font_blue);

	image.close();

	system("start cat.png");
	return 0;
}