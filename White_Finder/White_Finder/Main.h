#pragma once
#include <iostream> //OutPuts
#include <iomanip>
#include <fstream> //File Writing
#include <vector> //Lists
#include <sstream> //String Streams
#include <Windows.h>
#include <filesystem>
#include <array>



#pragma region console colours shits

inline std::ostream& blue(std::ostream &s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, FOREGROUND_BLUE
		| FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	return s;
}

inline std::ostream& red(std::ostream &s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout,
		FOREGROUND_RED | FOREGROUND_INTENSITY);
	return s;
}

inline std::ostream& green(std::ostream &s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout,
		FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	return s;
}

inline std::ostream& yellow(std::ostream &s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout,
		FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
	return s;
}

inline std::ostream& white(std::ostream &s)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout,
		FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	return s;
}

struct color {
	color(WORD attribute) :m_color(attribute) {};
	WORD m_color;
};

template <class _Elem, class _Traits>
std::basic_ostream<_Elem, _Traits>&
operator<<(std::basic_ostream<_Elem, _Traits>& i, color& c)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, c.m_color);
	return i;
}

#pragma endregion

namespace WhiteFinder {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	
	
	
	
	//Global variables go here
	std::ofstream Stream;
	bool fileload = false;
	
	/// <summary>
	/// Summary for Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			//makes console
			AllocConsole();
			freopen("CONOUT$", "w", stdout);

			this->Text = "WhiteFinder";
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  Load;
	private: System::Windows::Forms::PictureBox^  PB_Display;
	protected:


	private: System::Windows::Forms::Button^  Make_Map;
			 String^ FilePath;
			 Color CompColour = Color::FromArgb(255, 255, 255, 255);
			 Color pixelColor;
			 Bitmap ^ map;
			 String^ FileName;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->Load = (gcnew System::Windows::Forms::Button());
			this->PB_Display = (gcnew System::Windows::Forms::PictureBox());
			this->Make_Map = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_Display))->BeginInit();
			this->SuspendLayout();
			// 
			// Load
			// 
			this->Load->Location = System::Drawing::Point(12, 485);
			this->Load->Name = L"Load";
			this->Load->Size = System::Drawing::Size(75, 23);
			this->Load->TabIndex = 0;
			this->Load->Text = L"Load file";
			this->Load->UseVisualStyleBackColor = true;
			this->Load->Click += gcnew System::EventHandler(this, &Main::Load_Click);
			// 
			// PB_Display
			// 
			this->PB_Display->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->PB_Display->Location = System::Drawing::Point(12, 12);
			this->PB_Display->Name = L"PB_Display";
			this->PB_Display->Size = System::Drawing::Size(1013, 97);
			this->PB_Display->TabIndex = 1;
			this->PB_Display->TabStop = false;
			// 
			// Make_Map
			// 
			this->Make_Map->Location = System::Drawing::Point(950, 485);
			this->Make_Map->Name = L"Make_Map";
			this->Make_Map->Size = System::Drawing::Size(75, 23);
			this->Make_Map->TabIndex = 2;
			this->Make_Map->Text = L"Make Map";
			this->Make_Map->UseVisualStyleBackColor = true;
			this->Make_Map->Click += gcnew System::EventHandler(this, &Main::Make_Map_Click);
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Fuchsia;
			this->ClientSize = System::Drawing::Size(1037, 520);
			this->Controls->Add(this->Make_Map);
			this->Controls->Add(this->PB_Display);
			this->Controls->Add(this->Load);
			this->Name = L"Main";
			this->Text = L"Main";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PB_Display))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void Load_Click(System::Object^  sender, System::EventArgs^  e);
	
	private: System::Void Make_Map_Click(System::Object^  sender, System::EventArgs^  e);
	
private: System::Void maskedTextBox1_MaskInputRejected(System::Object^  sender, System::Windows::Forms::MaskInputRejectedEventArgs^  e) {
}
};
}
