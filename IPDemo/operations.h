#include <windows.h>

void OpenImage(System::Windows::Forms::PictureBox^ picOriginal);
void SaveImage(System::Windows::Forms::PictureBox^ picSave);
void GetGrayImage(System::Windows::Forms::PictureBox^ picGray, System::Windows::Forms::DataVisualization::Charting::Chart^ chart, System::Windows::Forms::ListBox^ listGray);
void GetGrayOtsuImage(System::Windows::Forms::PictureBox^ convertedPic);
void GetSmoothImage(System::Windows::Forms::PictureBox^ convertedPic, System::Windows::Forms::DataVisualization::Charting::Chart^ chart, System::Windows::Forms::ListBox^ listGauss);
void GetGradientImage(System::Windows::Forms::PictureBox^ convertedPic, System::Windows::Forms::DataVisualization::Charting::Chart^ chart, System::Windows::Forms::ListBox^ listEdge);
void GetNonMaxSupImage(System::Windows::Forms::PictureBox^ convertedPic, System::Windows::Forms::DataVisualization::Charting::Chart^ chart, System::Windows::Forms::ListBox^ listEdge);
void GetBinaryEdgeImage(System::Windows::Forms::PictureBox^ convertedPic, System::Windows::Forms::DataVisualization::Charting::Chart^ chart, System::Windows::Forms::ListBox^ listEdge);
void GetDilationImage(System::Windows::Forms::PictureBox^ convertedPic);
void GetErosionImage(System::Windows::Forms::PictureBox^ convertedPic);
void GetDilationErosionImage(System::Windows::Forms::PictureBox^ convertedPic);
void GetErosionDilationImage(System::Windows::Forms::PictureBox^ convertedPic, System::Windows::Forms::DataVisualization::Charting::Chart^ chart, System::Windows::Forms::ListBox^ listEdge);
void GetTaggedImage(System::Windows::Forms::PictureBox^ convertedPic, System::Windows::Forms::DataVisualization::Charting::Chart^ chart, System::Windows::Forms::ListBox^ listEdge);
