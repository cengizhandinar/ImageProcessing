#pragma once
#include <windows.h>
#include "operations.h"
#include <atlstr.h>
#include <string>
namespace IPDemo {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:	MyForm(void)
	{
		InitializeComponent();
	}
	protected: ~MyForm()
	{
		if (components)
			delete components;
	}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::PictureBox^ picOriginal;
	private: System::Windows::Forms::PictureBox^ picGray;
	private: System::Windows::Forms::ListBox^ listGray;
	private: System::Windows::Forms::ToolStripMenuItem^ btnOpen;
	private: System::Windows::Forms::ToolStripMenuItem^ btnSave;
	private: System::Windows::Forms::ToolStripMenuItem^ convertToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ btnOtsu;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chartHist;
	private: System::Windows::Forms::ListBox^ listGauss;
	private: System::Windows::Forms::ToolStripMenuItem^ btnGraMag;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ListBox^ listMagnitude;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::ToolStripMenuItem^ btnGaussian;
	private: System::Windows::Forms::ToolStripMenuItem^ btnNonMax;
	private: System::Windows::Forms::ToolStripMenuItem^ btnBinaryEdge;
	private: System::Windows::Forms::ListBox^ listNonMax;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::ListBox^ listBinary;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::ToolStripMenuItem^ ýmageSegmentationCllassificationToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ btnOtsuSegCls;
	private: System::Windows::Forms::ToolStripMenuItem^ btnDilation;
	private: System::Windows::Forms::ToolStripMenuItem^ btnErosion;
	private: System::Windows::Forms::ToolStripMenuItem^ btnErosionDilation;
	private: System::Windows::Forms::ToolStripMenuItem^ btnDilationErosion;
	private: System::Windows::Forms::ToolStripMenuItem^ btnTagging;
	private: System::Windows::Forms::PictureBox^ convertedPic;
	private: System::ComponentModel::Container^ components;
#pragma region Windows Form Designer generated code
		   void InitializeComponent(void)
		   {
			   System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			   System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			   this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			   this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->btnOpen = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->btnSave = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->convertToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->btnOtsu = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->btnGaussian = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->btnGraMag = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->btnNonMax = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->btnBinaryEdge = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->ýmageSegmentationCllassificationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->btnOtsuSegCls = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->btnDilation = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->btnErosion = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->btnErosionDilation = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->btnDilationErosion = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->btnTagging = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->picOriginal = (gcnew System::Windows::Forms::PictureBox());
			   this->picGray = (gcnew System::Windows::Forms::PictureBox());
			   this->listGray = (gcnew System::Windows::Forms::ListBox());
			   this->chartHist = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			   this->listGauss = (gcnew System::Windows::Forms::ListBox());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->listMagnitude = (gcnew System::Windows::Forms::ListBox());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->listNonMax = (gcnew System::Windows::Forms::ListBox());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->listBinary = (gcnew System::Windows::Forms::ListBox());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->convertedPic = (gcnew System::Windows::Forms::PictureBox());
			   this->menuStrip1->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picOriginal))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picGray))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartHist))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->convertedPic))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // menuStrip1
			   // 
			   this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				   this->fileToolStripMenuItem,
					   this->convertToolStripMenuItem, this->ýmageSegmentationCllassificationToolStripMenuItem
			   });
			   this->menuStrip1->Location = System::Drawing::Point(0, 0);
			   this->menuStrip1->Name = L"menuStrip1";
			   this->menuStrip1->Size = System::Drawing::Size(1621, 26);
			   this->menuStrip1->TabIndex = 0;
			   this->menuStrip1->Text = L"menuStrip1";
			   // 
			   // fileToolStripMenuItem
			   // 
			   this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				   this->btnOpen,
					   this->btnSave
			   });
			   this->fileToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(162)));
			   this->fileToolStripMenuItem->ForeColor = System::Drawing::Color::Indigo;
			   this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			   this->fileToolStripMenuItem->Size = System::Drawing::Size(46, 22);
			   this->fileToolStripMenuItem->Text = L"File";
			   // 
			   // btnOpen
			   // 
			   this->btnOpen->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(162)));
			   this->btnOpen->ForeColor = System::Drawing::Color::DarkRed;
			   this->btnOpen->Name = L"btnOpen";
			   this->btnOpen->Size = System::Drawing::Size(108, 24);
			   this->btnOpen->Text = L"Open";
			   this->btnOpen->Click += gcnew System::EventHandler(this, &MyForm::btnOpen_Click);
			   // 
			   // btnSave
			   // 
			   this->btnSave->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold));
			   this->btnSave->ForeColor = System::Drawing::Color::DarkRed;
			   this->btnSave->Name = L"btnSave";
			   this->btnSave->Size = System::Drawing::Size(108, 24);
			   this->btnSave->Text = L"Save";
			   this->btnSave->Click += gcnew System::EventHandler(this, &MyForm::btnSave_Click);
			   // 
			   // convertToolStripMenuItem
			   // 
			   this->convertToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				   this->btnOtsu,
					   this->btnGaussian, this->btnGraMag, this->btnNonMax, this->btnBinaryEdge
			   });
			   this->convertToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold));
			   this->convertToolStripMenuItem->ForeColor = System::Drawing::Color::Indigo;
			   this->convertToolStripMenuItem->Name = L"convertToolStripMenuItem";
			   this->convertToolStripMenuItem->Size = System::Drawing::Size(130, 22);
			   this->convertToolStripMenuItem->Text = L"Edge Detection";
			   // 
			   // btnOtsu
			   // 
			   this->btnOtsu->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold));
			   this->btnOtsu->ForeColor = System::Drawing::Color::DarkRed;
			   this->btnOtsu->Name = L"btnOtsu";
			   this->btnOtsu->Size = System::Drawing::Size(269, 24);
			   this->btnOtsu->Text = L"Otsu (Gray)";
			   this->btnOtsu->Click += gcnew System::EventHandler(this, &MyForm::btnOtsu_Click);
			   // 
			   // btnGaussian
			   // 
			   this->btnGaussian->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold));
			   this->btnGaussian->ForeColor = System::Drawing::Color::DarkRed;
			   this->btnGaussian->Name = L"btnGaussian";
			   this->btnGaussian->Size = System::Drawing::Size(269, 24);
			   this->btnGaussian->Text = L"Gaussian Blur (5*5)";
			   this->btnGaussian->Click += gcnew System::EventHandler(this, &MyForm::btnGaussian_Click);
			   // 
			   // btnGraMag
			   // 
			   this->btnGraMag->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold));
			   this->btnGraMag->ForeColor = System::Drawing::Color::DarkRed;
			   this->btnGraMag->Name = L"btnGraMag";
			   this->btnGraMag->Size = System::Drawing::Size(269, 24);
			   this->btnGraMag->Text = L"Gradient Magnitude (SobelXY)";
			   this->btnGraMag->Click += gcnew System::EventHandler(this, &MyForm::btnGraMag_Click);
			   // 
			   // btnNonMax
			   // 
			   this->btnNonMax->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold));
			   this->btnNonMax->ForeColor = System::Drawing::Color::DarkRed;
			   this->btnNonMax->Name = L"btnNonMax";
			   this->btnNonMax->Size = System::Drawing::Size(269, 24);
			   this->btnNonMax->Text = L"NonMaximumSuppression";
			   this->btnNonMax->Click += gcnew System::EventHandler(this, &MyForm::btnNonMax_Click);
			   // 
			   // btnBinaryEdge
			   // 
			   this->btnBinaryEdge->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold));
			   this->btnBinaryEdge->ForeColor = System::Drawing::Color::DarkRed;
			   this->btnBinaryEdge->Name = L"btnBinaryEdge";
			   this->btnBinaryEdge->Size = System::Drawing::Size(269, 24);
			   this->btnBinaryEdge->Text = L"Binary Image";
			   this->btnBinaryEdge->Click += gcnew System::EventHandler(this, &MyForm::btnBinaryEdge_Click);
			   // 
			   // ýmageSegmentationCllassificationToolStripMenuItem
			   // 
			   this->ýmageSegmentationCllassificationToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				   this->btnOtsuSegCls,
					   this->btnDilation, this->btnErosion, this->btnErosionDilation, this->btnDilationErosion, this->btnTagging
			   });
			   this->ýmageSegmentationCllassificationToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold));
			   this->ýmageSegmentationCllassificationToolStripMenuItem->ForeColor = System::Drawing::Color::Indigo;
			   this->ýmageSegmentationCllassificationToolStripMenuItem->Name = L"ýmageSegmentationCllassificationToolStripMenuItem";
			   this->ýmageSegmentationCllassificationToolStripMenuItem->Size = System::Drawing::Size(264, 22);
			   this->ýmageSegmentationCllassificationToolStripMenuItem->Text = L"Image Segmentation-Classification";
			   // 
			   // btnOtsuSegCls
			   // 
			   this->btnOtsuSegCls->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold));
			   this->btnOtsuSegCls->ForeColor = System::Drawing::Color::DarkRed;
			   this->btnOtsuSegCls->Name = L"btnOtsuSegCls";
			   this->btnOtsuSegCls->Size = System::Drawing::Size(167, 24);
			   this->btnOtsuSegCls->Text = L"Otsu (Gray)";
			   this->btnOtsuSegCls->Click += gcnew System::EventHandler(this, &MyForm::btnOtsuSegCls_Click);
			   // 
			   // btnDilation
			   // 
			   this->btnDilation->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold));
			   this->btnDilation->ForeColor = System::Drawing::Color::DarkRed;
			   this->btnDilation->Name = L"btnDilation";
			   this->btnDilation->Size = System::Drawing::Size(167, 24);
			   this->btnDilation->Text = L"Dilation";
			   this->btnDilation->Click += gcnew System::EventHandler(this, &MyForm::btnDilation_Click);
			   // 
			   // btnErosion
			   // 
			   this->btnErosion->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold));
			   this->btnErosion->ForeColor = System::Drawing::Color::DarkRed;
			   this->btnErosion->Name = L"btnErosion";
			   this->btnErosion->Size = System::Drawing::Size(167, 24);
			   this->btnErosion->Text = L"Erosion";
			   this->btnErosion->Click += gcnew System::EventHandler(this, &MyForm::btnErosion_Click);
			   // 
			   // btnErosionDilation
			   // 
			   this->btnErosionDilation->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold));
			   this->btnErosionDilation->ForeColor = System::Drawing::Color::DarkRed;
			   this->btnErosionDilation->Name = L"btnErosionDilation";
			   this->btnErosionDilation->Size = System::Drawing::Size(167, 24);
			   this->btnErosionDilation->Text = L"Opening (E-D)";
			   this->btnErosionDilation->Click += gcnew System::EventHandler(this, &MyForm::btnErosionDilation_Click);
			   // 
			   // btnDilationErosion
			   // 
			   this->btnDilationErosion->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold));
			   this->btnDilationErosion->ForeColor = System::Drawing::Color::DarkRed;
			   this->btnDilationErosion->Name = L"btnDilationErosion";
			   this->btnDilationErosion->Size = System::Drawing::Size(167, 24);
			   this->btnDilationErosion->Text = L"Closing (D-E)";
			   this->btnDilationErosion->Click += gcnew System::EventHandler(this, &MyForm::btnDilationErosion_Click);
			   // 
			   // btnTagging
			   // 
			   this->btnTagging->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 9.75F, System::Drawing::FontStyle::Bold));
			   this->btnTagging->ForeColor = System::Drawing::Color::DarkRed;
			   this->btnTagging->Name = L"btnTagging";
			   this->btnTagging->Size = System::Drawing::Size(167, 24);
			   this->btnTagging->Text = L"Tagging";
			   this->btnTagging->Click += gcnew System::EventHandler(this, &MyForm::btnTagging_Click);
			   // 
			   // picOriginal
			   // 
			   this->picOriginal->BackColor = System::Drawing::Color::LightGray;
			   this->picOriginal->Location = System::Drawing::Point(12, 54);
			   this->picOriginal->Name = L"picOriginal";
			   this->picOriginal->Size = System::Drawing::Size(394, 355);
			   this->picOriginal->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->picOriginal->TabIndex = 1;
			   this->picOriginal->TabStop = false;
			   // 
			   // picGray
			   // 
			   this->picGray->BackColor = System::Drawing::Color::LightGray;
			   this->picGray->Location = System::Drawing::Point(412, 54);
			   this->picGray->Name = L"picGray";
			   this->picGray->Size = System::Drawing::Size(394, 355);
			   this->picGray->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->picGray->TabIndex = 2;
			   this->picGray->TabStop = false;
			   // 
			   // listGray
			   // 
			   this->listGray->BackColor = System::Drawing::Color::LightGray;
			   this->listGray->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(162)));
			   this->listGray->ForeColor = System::Drawing::Color::SeaGreen;
			   this->listGray->FormattingEnabled = true;
			   this->listGray->ItemHeight = 16;
			   this->listGray->Location = System::Drawing::Point(812, 54);
			   this->listGray->Name = L"listGray";
			   this->listGray->Size = System::Drawing::Size(156, 724);
			   this->listGray->TabIndex = 5;
			   // 
			   // chartHist
			   // 
			   this->chartHist->BackColor = System::Drawing::Color::LightGray;
			   this->chartHist->BorderlineColor = System::Drawing::Color::Transparent;
			   chartArea2->AxisX->ArrowStyle = System::Windows::Forms::DataVisualization::Charting::AxisArrowStyle::Triangle;
			   chartArea2->AxisX->Interval = 25;
			   chartArea2->AxisX->IsStartedFromZero = false;
			   chartArea2->AxisX->LineColor = System::Drawing::Color::Brown;
			   chartArea2->AxisX->Maximum = 256;
			   chartArea2->AxisX->Minimum = -1;
			   chartArea2->AxisY->ArrowStyle = System::Windows::Forms::DataVisualization::Charting::AxisArrowStyle::Triangle;
			   chartArea2->AxisY->LineColor = System::Drawing::Color::Brown;
			   chartArea2->BackColor = System::Drawing::Color::LightGray;
			   chartArea2->InnerPlotPosition->Auto = false;
			   chartArea2->InnerPlotPosition->Height = 89.58112F;
			   chartArea2->InnerPlotPosition->Width = 91;
			   chartArea2->InnerPlotPosition->X = 7.5F;
			   chartArea2->InnerPlotPosition->Y = 3;
			   chartArea2->Name = L"ChartArea1";
			   chartArea2->Position->Auto = false;
			   chartArea2->Position->Height = 94;
			   chartArea2->Position->Width = 94;
			   chartArea2->Position->X = 3;
			   chartArea2->Position->Y = 3;
			   this->chartHist->ChartAreas->Add(chartArea2);
			   this->chartHist->Location = System::Drawing::Point(12, 415);
			   this->chartHist->Name = L"chartHist";
			   this->chartHist->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::None;
			   series2->BackSecondaryColor = System::Drawing::Color::Transparent;
			   series2->BorderColor = System::Drawing::Color::Black;
			   series2->BorderWidth = 0;
			   series2->ChartArea = L"ChartArea1";
			   series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Area;
			   series2->Color = System::Drawing::Color::Brown;
			   series2->CustomProperties = L"EmptyPointValue=Zero";
			   series2->EmptyPointStyle->Color = System::Drawing::Color::Transparent;
			   series2->Name = L"hist";
			   this->chartHist->Series->Add(series2);
			   this->chartHist->Size = System::Drawing::Size(394, 363);
			   this->chartHist->TabIndex = 8;
			   this->chartHist->Text = L"chartHist";
			   // 
			   // listGauss
			   // 
			   this->listGauss->BackColor = System::Drawing::Color::LightGray;
			   this->listGauss->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(162)));
			   this->listGauss->ForeColor = System::Drawing::Color::SeaGreen;
			   this->listGauss->FormattingEnabled = true;
			   this->listGauss->ItemHeight = 16;
			   this->listGauss->Location = System::Drawing::Point(974, 54);
			   this->listGauss->Name = L"listGauss";
			   this->listGauss->Size = System::Drawing::Size(153, 724);
			   this->listGauss->TabIndex = 9;
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(162)));
			   this->label1->ForeColor = System::Drawing::Color::IndianRed;
			   this->label1->Location = System::Drawing::Point(838, 35);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(101, 16);
			   this->label1->TabIndex = 10;
			   this->label1->Text = L"Gray Pixel List";
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(162)));
			   this->label2->ForeColor = System::Drawing::Color::IndianRed;
			   this->label2->Location = System::Drawing::Point(986, 35);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(129, 16);
			   this->label2->TabIndex = 11;
			   this->label2->Text = L"Gaussian Pixel List";
			   // 
			   // listMagnitude
			   // 
			   this->listMagnitude->BackColor = System::Drawing::Color::LightGray;
			   this->listMagnitude->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(162)));
			   this->listMagnitude->ForeColor = System::Drawing::Color::SeaGreen;
			   this->listMagnitude->FormattingEnabled = true;
			   this->listMagnitude->ItemHeight = 16;
			   this->listMagnitude->Location = System::Drawing::Point(1133, 54);
			   this->listMagnitude->Name = L"listMagnitude";
			   this->listMagnitude->Size = System::Drawing::Size(157, 724);
			   this->listMagnitude->TabIndex = 12;
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold));
			   this->label3->ForeColor = System::Drawing::Color::IndianRed;
			   this->label3->Location = System::Drawing::Point(1142, 35);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(138, 16);
			   this->label3->TabIndex = 13;
			   this->label3->Text = L"Magnitude Pixel List";
			   // 
			   // listNonMax
			   // 
			   this->listNonMax->BackColor = System::Drawing::Color::LightGray;
			   this->listNonMax->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(162)));
			   this->listNonMax->ForeColor = System::Drawing::Color::SeaGreen;
			   this->listNonMax->FormattingEnabled = true;
			   this->listNonMax->ItemHeight = 16;
			   this->listNonMax->Location = System::Drawing::Point(1296, 54);
			   this->listNonMax->Name = L"listNonMax";
			   this->listNonMax->Size = System::Drawing::Size(154, 724);
			   this->listNonMax->TabIndex = 14;
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold));
			   this->label4->ForeColor = System::Drawing::Color::IndianRed;
			   this->label4->Location = System::Drawing::Point(1309, 35);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(127, 16);
			   this->label4->TabIndex = 15;
			   this->label4->Text = L"Non Max Pixel List";
			   // 
			   // listBinary
			   // 
			   this->listBinary->BackColor = System::Drawing::Color::LightGray;
			   this->listBinary->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(162)));
			   this->listBinary->ForeColor = System::Drawing::Color::SeaGreen;
			   this->listBinary->FormattingEnabled = true;
			   this->listBinary->ItemHeight = 16;
			   this->listBinary->Location = System::Drawing::Point(1456, 54);
			   this->listBinary->Name = L"listBinary";
			   this->listBinary->Size = System::Drawing::Size(156, 724);
			   this->listBinary->TabIndex = 16;
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold));
			   this->label5->ForeColor = System::Drawing::Color::IndianRed;
			   this->label5->Location = System::Drawing::Point(1477, 35);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(112, 16);
			   this->label5->TabIndex = 17;
			   this->label5->Text = L"Binary Pixel List";
			   // 
			   // convertedPic
			   // 
			   this->convertedPic->BackColor = System::Drawing::Color::LightGray;
			   this->convertedPic->Location = System::Drawing::Point(412, 415);
			   this->convertedPic->Name = L"convertedPic";
			   this->convertedPic->Size = System::Drawing::Size(394, 355);
			   this->convertedPic->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			   this->convertedPic->TabIndex = 18;
			   this->convertedPic->TabStop = false;
			   // 
			   // MyForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->BackColor = System::Drawing::Color::Linen;
			   this->ClientSize = System::Drawing::Size(1621, 784);
			   this->Controls->Add(this->convertedPic);
			   this->Controls->Add(this->label5);
			   this->Controls->Add(this->listBinary);
			   this->Controls->Add(this->label4);
			   this->Controls->Add(this->listNonMax);
			   this->Controls->Add(this->label3);
			   this->Controls->Add(this->listMagnitude);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->label1);
			   this->Controls->Add(this->listGauss);
			   this->Controls->Add(this->chartHist);
			   this->Controls->Add(this->listGray);
			   this->Controls->Add(this->picGray);
			   this->Controls->Add(this->picOriginal);
			   this->Controls->Add(this->menuStrip1);
			   this->MainMenuStrip = this->menuStrip1;
			   this->Name = L"MyForm";
			   this->Text = L"MyForm";
			   this->menuStrip1->ResumeLayout(false);
			   this->menuStrip1->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picOriginal))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picGray))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartHist))->EndInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->convertedPic))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
		   Void btnOpen_Click(System::Object^ sender, System::EventArgs^ e)
		   {
			   OpenImage(picOriginal);
			   GetGrayImage(picGray, chartHist, listGray);
		   }
		   Void btnSave_Click(System::Object^ sender, System::EventArgs^ e)
		   {
			   if (picOriginal->Image != nullptr)
			   {
				   if (convertedPic->Image != nullptr)
					   SaveImage(convertedPic);
				   else
					   MessageBox::Show("Please convert the image first", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			   }
			   else
				   MessageBox::Show("Please open the image first", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		   }
		   Void btnOtsu_Click(System::Object^ sender, System::EventArgs^ e)
		   {
			   if (picOriginal->Image != nullptr)
			   {
				   GetGrayOtsuImage(convertedPic);
			   }
			   else
				   MessageBox::Show("Please open the image first", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		   }
		   Void btnGaussian_Click(System::Object^ sender, System::EventArgs^ e)
		   {
			   if (picOriginal->Image != nullptr)
			   {
				   GetSmoothImage(convertedPic, chartHist, listGauss);
			   }
			   else
				   MessageBox::Show("Please open the image first", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		   }
		   Void btnGraMag_Click(System::Object^ sender, System::EventArgs^ e)
		   {
			   if (picOriginal->Image != nullptr)
			   {
				   GetGradientImage(convertedPic, chartHist, listMagnitude);
			   }
			   else
				   MessageBox::Show("Please open the image first", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		   }
		   Void btnNonMax_Click(System::Object^ sender, System::EventArgs^ e)
		   {
			   if (picOriginal->Image != nullptr)
			   {
				   GetNonMaxSupImage(convertedPic, chartHist, listNonMax);
			   }
			   else
				   MessageBox::Show("Please open the image first", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		   }
		   Void btnBinaryEdge_Click(System::Object^ sender, System::EventArgs^ e)
		   {
			   if (picOriginal->Image != nullptr)
			   {
				   GetBinaryEdgeImage(convertedPic, chartHist, listBinary);
			   }
			   else
				   MessageBox::Show("Please open the image first", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		   }
		   Void btnOtsuSegCls_Click(System::Object^ sender, System::EventArgs^ e)
		   {
			   if (picOriginal->Image != nullptr)
			   {
				   GetGrayOtsuImage(convertedPic);
			   }
			   else
				   MessageBox::Show("Please open the image first", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		   }
		   Void btnDilation_Click(System::Object^ sender, System::EventArgs^ e)
		   {
			   if (picOriginal->Image != nullptr)
			   {
				   GetDilationImage(convertedPic);
			   }
			   else
				   MessageBox::Show("Please open the image first", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		   }
		   Void btnErosion_Click(System::Object^ sender, System::EventArgs^ e)
		   {
			   if (picOriginal->Image != nullptr)
			   {
				   GetErosionImage(convertedPic);
			   }
			   else
				   MessageBox::Show("Please open the image first", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		   }
		   Void btnErosionDilation_Click(System::Object^ sender, System::EventArgs^ e)
		   {
			   if (picOriginal->Image != nullptr)
			   {
				   GetErosionDilationImage(convertedPic, chartHist, listGauss);
			   }
			   else
				   MessageBox::Show("Please open the image first", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		   }
		   Void btnDilationErosion_Click(System::Object^ sender, System::EventArgs^ e)
		   {
			   if (picOriginal->Image != nullptr)
			   {
				   GetDilationErosionImage(convertedPic);
			   }
			   else
				   MessageBox::Show("Please open the image first", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		   }
		   Void btnTagging_Click(System::Object^ sender, System::EventArgs^ e)
		   {
			   GetTaggedImage(convertedPic, chartHist, listMagnitude);
		   }
	};
}