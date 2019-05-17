#include "Main.h"
#include <msclr\marshal.h>
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace System::Windows::Forms;
//using namespace msclr::interop;

//ENTRY POINT OF THE PROGRAM
[STAThread]
void main()
{

	Application::EnableVisualStyles(); //Additional Styling Options
	Application::SetCompatibleTextRenderingDefault(false); //Multiple Fonts

	WhiteFinder::Main MainEditor; //Create the Main Form
	Application::Run(%MainEditor); //Run the program
}

 System::Void WhiteFinder::Main::Load_Click(System::Object^  sender, System::EventArgs^  e)
{
	 String^ ImgPath = gcnew String("");
	 OpenFileDialog^ dia = gcnew OpenFileDialog();
	 dia->InitialDirectory = ImgPath;
	 dia->Filter = "BMP(*.bmp)|*.bmp| PNG(*.png)|*.png";
	 dia->FilterIndex = 0;
	 dia->RestoreDirectory = true;	 

	 if (dia->ShowDialog() == System::Windows::Forms::DialogResult::OK) 
	 {		 
		 FilePath = dia->FileName;
		 String^ sysTest = FilePath;

		 auto img = System::Drawing::Image::FromFile(FilePath);
		 map = gcnew System::Drawing::Bitmap(img);

		 this->PB_Display->BackgroundImage = img;

		 FileName = IO::Path::GetFileName(FilePath);
		 String^ sysName = FileName;

		 this->Text = "WhiteFinder-" + FileName;

		 //converts to std in function variable
		 std::string stdPath = msclr::interop::marshal_as< std::string >(sysTest);
		 std::string stdName = msclr::interop::marshal_as< std::string >(sysName);
		 fileload = true;
	 }
	 else 
	 {
		 std::cout << "why you do this" << std::endl;
	 }

}


 System::Void WhiteFinder::Main::Make_Map_Click(System::Object^  sender, System::EventArgs^  e)
 {

	 String^ sysName = FileName;
	 std::string stdName = msclr::interop::marshal_as< std::string >(sysName);

	 if (fileload)
	 {
	 
		 std::cout << map->Width << "," << map->Height;
		 SaveFileDialog^ dia = gcnew SaveFileDialog();
		 dia->Filter = "Text file(*.txt)|*.txt";
		 dia->RestoreDirectory = true;
		 if (dia->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		 {
			 String^ savename = dia->FileName;
			 std::string save = msclr::interop::marshal_as< std::string >(savename);


			 Stream.open(save, std::ios::out | std::ios::trunc);

			 if (Stream.is_open())
			 {				

				 //File header (width, height and name)
				 Stream << map->Width << ", " << map->Height <<", "<<stdName<<"*";

				 for (int i = 0; i < map->Width; i++)
				 {
					 for (int j = 0; j < map->Height; j++)
					 {
						 pixelColor = map->GetPixel(i, j);
						 if (pixelColor == CompColour)
						 {
							 Stream << 0;
						 }
						 else
						 {
							 Stream << 1;
						 }
						 
					 }
					 Stream << ",";
					 //Stream << std::endl;
				 }
				 MessageBox::Show("Map Made of " + FileName, "Map Made", MessageBoxButtons::OK, MessageBoxIcon::Information);

			 }
			 else
			 {
				 MessageBox::Show("Could not Write to File", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				 std::cout << red << "Error: Could Not Write to File -- Output.txt could not be written to, file missing?" << white << std::endl;
			 }
			 Stream.close();
		 }		
	 }
	 else
	 {
		 MessageBox::Show("Please load a file ", "Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
	 }
	
}