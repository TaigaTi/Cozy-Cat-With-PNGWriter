#pragma warning(disable: 4996)
#pragma comment(lib, "shell32.lib")

#define _CRT_SECURE_NO_WARNINGS
#include "pngwriter.h" 

/* Functions Used:
	1.  filledsquare
	2.  filledsquare_blend
	3.  filledtriangle
	4.  filledtriangle_blend
	5.  filledcircle
	6.  filledcircle_blend
	7.  filleddiamond
	8.  filledarrow
	9.  maltesecross
	10. polygon
	11. polygon_blend
	12. flood_fill
	13. flood_fill_blend
	14. line
*/

int main()
{
	int width = 1500;
	int height = 2000;

	pngwriter image(width, height, 1.0, "cat.png");

	// Wall & Window Frame
	image.filledsquare(0, 0, 1500, 2000, 0.5216, 0.3843, 0.3059); // Wall
	image.filledsquare(320, 720, 1180, 1780, 0.4392, 0.3059, 0.2314); // Window Frame

	// Sky
	image.filledsquare(400, 800, 1100, 1700 , 0.6314, 0.4039, 0.6); // Sky
	image.filledcircle(450, 1680, 100, 1.0, 1.0, 1.0); // Moon

	// Stars
	image.filleddiamond(580, 1000, 15, 22, 1.0, 1.0, 1.0);
	image.filleddiamond(1000, 940, 22, 32, 1.0, 1.0, 1.0);
	image.filleddiamond(1040, 980, 12, 20, 1.0, 1.0, 1.0);
	image.filleddiamond(1050, 1250, 20, 30, 1.0, 1.0, 1.0);
	image.filleddiamond(900, 1600, 18, 25, 1.0, 1.0, 1.0);
	image.filleddiamond(600, 1550, 18, 28, 1.0, 1.0, 1.0);
	image.filleddiamond(500, 1250, 18, 28, 1.0, 1.0, 1.0);

	// Window Bars
	image.filledsquare(320, 1700, 1180, 1780, 0.4392, 0.3059, 0.2314); // Top Window Frame
	image.filledsquare(320, 720, 400, 1780, 0.4392, 0.3059, 0.2314); // Left Window Frame
	image.filledsquare(320, 1360, 1180, 1420, 0.4392, 0.3059, 0.2314); // Second Horizontal Window Bar
	image.filledsquare(320, 1050, 1180, 1110, 0.4392, 0.3059, 0.2314); // Third Horizontal Window Bar
	image.filledsquare(720, 720, 780, 1780, 0.4392, 0.3059, 0.2314); // Vertical Window Bar

	int shelf_top = 230;

	// Plants
	// Left Plant Pot
	image.line(160, 820, 200, 1100, 0.6745, 0.5059, 0.4118);
	image.line(0, 1100,	200, 1100, 0.6745, 0.5059, 0.4118);
	image.line(0, 820, 160, 820, 0.6745, 0.5059, 0.4118);

	// Leaves
	image.filledtriangle_blend(0, 1550, 50, 1200, 0, 1200, 0.9, 0.459, 0.741, 0.545);


	// Right Plant
	image.line(1300, 1100, 1350, 820, 0.6745, 0.5059, 0.4118);
	image.line(1300, 1100, 1500, 1100, 0.6745, 0.5059, 0.4118);
	image.line(1300, 820, 1500, 820, 0.6745, 0.5059, 0.4118);

	// Book Shelf
	image.filledsquare(0, 0, width, 820, 0.7765, 0.6196, 0.5137); // Top
	image.filledsquare(0, 0, width, 650, 0.6745, 0.5059, 0.4118); // Edge
	image.filledsquare(0, 0, width, 600, 0.4392, 0.3059, 0.2314); // Back
	image.filledsquare(0, 200, width, shelf_top, 0.6745, 0.5059, 0.4118); // Shelf

	// Top Shelf Books (Ordered Left to Right)
	// Red Book 
	image.filledsquare(0, shelf_top, 220, 560, 0.5294, 0.2510, 0.2863);
	image.maltesecross(100, 405, 100, 150, 50, 50, 0.7569, 0.5373, 0.5569);

	// Yellow Book
	image.filledsquare(220, shelf_top, 320, 500, 0.9137, 0.7176, 0.4980);
	image.filledsquare(220, 270, 320, 295, 0.8667, 0.5961, 0.4431);
	image.filledsquare(220, 435, 320, 460, 0.8667, 0.5961, 0.4431);

	// Orange Book
	image.filledsquare(320, shelf_top, 439, 570, 0.8039, 0.4431, 0.3804);
	image.filleddiamond(380, 470, 50, 70, 0.9451, 0.8196, 0.6706);
	image.filledcircle(380, 400, 12, 0.9451, 0.8196, 0.6706);

	// Green Book
	int green_book_xcenter = 520;

	image.filledsquare(440, shelf_top, 600, 520, 0.5451, 0.6392, 0.5569);
	image.filledsquare(440, 470, 600, green_book_xcenter, 0.3922, 0.5451, 0.4980);
	image.filledcircle(green_book_xcenter - 15, 320, 18, 0.3922, 0.5451, 0.4980);
	image.filledcircle(green_book_xcenter + 15, 320, 18, 0.3922, 0.5451, 0.4980);
	image.filledtriangle(green_book_xcenter, 285, green_book_xcenter - 30, 310, green_book_xcenter + 30, 310, 0.3922, 0.5451, 0.4980);

	// Purple Book
	image.filledsquare(600, shelf_top, 770, 565, 0.5176, 0.3569, 0.6039);
	image.filleddiamond(685, 460, 60, 80, 0.7529, 0.6667, 0.8353);
	image.filleddiamond(685, 370, 40, 50, 0.7529, 0.6667, 0.8353);

	// Blue Book
	image.filledsquare(771, shelf_top, 880, 520, 0.2392, 0.2824, 0.5137);
	image.filledarrow(825, 350, 825, 450, 40, 100, 0.5176, 0.5451, 0.7098);

	// Light Blue Book 
	image.filledsquare(880, shelf_top, 999, 545, 0.4824, 0.5451, 0.5725);
	image.filledcircle(940, 475, 25, 0.70196, 0.7451, 0.7647);

	// Navy Blue Book
	image.filledsquare(1000, shelf_top, 1149, 500, 0.1451, 0.2784, 0.4039);
	image.filleddiamond(1075, 390, 70, 80, 0.5725, 0.6392, 0.6706);

	// Red Book
	image.filledsquare(1150, shelf_top, 1250, 460, 0.5294, 0.2510, 0.2863);
	image.filledarrow(1200, 400, 1200, 300, 40, 100, 0.7647, 0.5412, 0.5608);

	// Yellow Book
	const int num_book_polygon_points = 5;
	int yellow_book_polygon_points[num_book_polygon_points * 2] = { 1250, 550, 1290, 500, 1350, 500, 1390, 550, 1250, 550 };

	image.filledsquare(1250, shelf_top, 1390, 550, 0.8667, 0.6275, 0.4275);
	image.polygon(yellow_book_polygon_points, num_book_polygon_points, 0.922, 0.780, 0.584);
	image.flood_fill(1350, 520, 0.922, 0.780, 0.584);

	// Pink Book
	image.filledsquare(1390, shelf_top, 1500, 600, 0.8235, 0.5098, 0.6980);

	// Bottom Shelf (Right to Left)
	// Orange Book
	image.filledsquare(1350, 0, 1500, 100, 0.8039, 0.4431, 0.3804);
	image.maltesecross(1425, 30, 50, 70, 30, 30, 0.9451, 0.8196, 0.6706);

	// Purple Book
	image.filledsquare(1200, 0, 1350, 170, 0.5176, 0.3569, 0.6039);
	image.filledcircle(1275, 100,25, 0.7529, 0.6667, 0.8353);
	image.filledcircle(1275, 40, 15, 0.7529, 0.6667, 0.8353);

	// Yellow Book
	image.filledsquare(1050, 0, 1200, 125, 0.9137, 0.7176, 0.4980);
	image.filledsquare_blend(1050, 80, 1200, 125, 0.3, 0.8039, 0.4431, 0.3804);

	// Pink
	image.filledsquare(930, 0, 1050, 90, 0.8235, 0.5098, 0.6980);
	image.filledcircle_blend(990, 15, 30, 0.3, 1.0, 1.0, 1.0);

	// Plant
	image.filledtriangle(860, 0, 860, 120, 780, 0, 0.459, 0.741, 0.545);
	image.filledtriangle(750, 0, 710, 170 , 660, 0, 0.459, 0.741, 0.545);
	image.filledtriangle(640, 0, 545, 140, 540, 0, 0.459, 0.741, 0.545);

	// Frame
	image.filledsquare(100, 0, 400, 120, 0.816, 0.580, 0.471);
	image.filledsquare(130, 0, 370, 90, 0.627, 0.784, 0.882); 

	const int num_frame_polygon_points = 5;
	int frame_polygon_points[num_frame_polygon_points * 2] = { 400, 0, 400, 120, 440, 90, 440, 0, 400, 0 };

	image.polygon_blend(frame_polygon_points, num_frame_polygon_points, 0.9, 0.659, 0.384, 0.345);
	image.flood_fill_blend(420, 40, 0.9, 0.659, 0.384, 0.345);

	// Framed Image
	image.filledtriangle(165, 0, 215, 65, 265, 0, 0.3922, 0.5451, 0.4980);
	image.filledtriangle(265, 0, 295, 25, 325, 0, 0.3922, 0.5451, 0.4980);
	image.filledcircle(330, 60, 12, 0.9137, 0.7176, 0.4980);

	image.close();
	return 0;
}