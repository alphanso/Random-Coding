#pragma once
#include "global_var.h"


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace AStar {

	/// <summary>
	/// Summary for Form_8Puzzle
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form_8Puzzle : public System::Windows::Forms::Form
	{

	


	public:
		Form_8Puzzle(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form_8Puzzle()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button10;
	private: System::Windows::Forms::DataGridView^  dataGridView1;



	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;



	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  label;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  reached;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  expanded;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  leangth;













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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->reached = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->expanded = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->leangth = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(12, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(57, 51);
			this->button1->TabIndex = 0;
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(75, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(57, 51);
			this->button2->TabIndex = 1;
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(138, 12);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(57, 51);
			this->button3->TabIndex = 2;
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(12, 69);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(57, 51);
			this->button4->TabIndex = 3;
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(75, 69);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(57, 51);
			this->button5->TabIndex = 4;
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(138, 69);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(57, 51);
			this->button6->TabIndex = 5;
			this->button6->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button7->Location = System::Drawing::Point(12, 126);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(57, 51);
			this->button7->TabIndex = 6;
			this->button7->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button8->Location = System::Drawing::Point(75, 126);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(57, 51);
			this->button8->TabIndex = 7;
			this->button8->UseVisualStyleBackColor = true;
			// 
			// button9
			// 
			this->button9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button9->Location = System::Drawing::Point(138, 126);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(57, 51);
			this->button9->TabIndex = 8;
			this->button9->UseVisualStyleBackColor = true;
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(236, 83);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(75, 23);
			this->button10->TabIndex = 0;
			this->button10->Text = L"Solve!";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &Form_8Puzzle::button10_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {this->label, 
				this->reached, this->expanded, this->leangth});
			this->dataGridView1->Location = System::Drawing::Point(358, 43);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(444, 169);
			this->dataGridView1->TabIndex = 10;
			// 
			// label
			// 
			this->label->HeaderText = L"";
			this->label->Name = L"label";
			this->label->ReadOnly = true;
			// 
			// reached
			// 
			this->reached->HeaderText = L"# reached nodes";
			this->reached->Name = L"reached";
			this->reached->ReadOnly = true;
			this->reached->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			// 
			// expanded
			// 
			this->expanded->HeaderText = L"# expanded nodes";
			this->expanded->Name = L"expanded";
			this->expanded->ReadOnly = true;
			// 
			// leangth
			// 
			this->leangth->HeaderText = L"path leangth";
			this->leangth->Name = L"leangth";
			this->leangth->ReadOnly = true;
			// 
			// button11
			// 
			this->button11->Enabled = false;
			this->button11->Location = System::Drawing::Point(236, 140);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(26, 23);
			this->button11->TabIndex = 11;
			this->button11->Text = L"<";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &Form_8Puzzle::button11_Click);
			// 
			// button12
			// 
			this->button12->Enabled = false;
			this->button12->Location = System::Drawing::Point(285, 140);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(26, 23);
			this->button12->TabIndex = 12;
			this->button12->Text = L">";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &Form_8Puzzle::button12_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(249, 17);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(88, 20);
			this->textBox1->TabIndex = 13;
			this->textBox1->Text = L"3,1,2,4,5,0,7,8,6";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(249, 43);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(88, 20);
			this->textBox2->TabIndex = 14;
			this->textBox2->Text = L"1,2,3,4,5,6,7,8,0";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(216, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(27, 13);
			this->label1->TabIndex = 15;
			this->label1->Text = L"start";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(216, 46);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(27, 13);
			this->label2->TabIndex = 16;
			this->label2->Text = L"goal";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::Red;
			this->label3->Location = System::Drawing::Point(413, 16);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(229, 17);
			this->label3->TabIndex = 17;
			this->label3->Text = L"Please wait while calculating...";
			this->label3->Visible = false;
			// 
			// Form_8Puzzle
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(839, 224);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button10);
			this->Controls->Add(this->button9);
			this->Controls->Add(this->button8);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"Form_8Puzzle";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"8 Puzzle";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


private: void update_buttons(State state){
			 this->button1->Text = state[0].ToString();
			 this->button2->Text = state[1].ToString();
			 this->button3->Text = state[2].ToString();
			 this->button4->Text = state[3].ToString();
			 this->button5->Text = state[4].ToString();
			 this->button6->Text = state[5].ToString();
			 this->button7->Text = state[6].ToString();
			 this->button8->Text = state[7].ToString();
			 this->button9->Text = state[8].ToString();
			 }


private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			 button11->Enabled = false;
			 button12->Enabled = false;

			 State start = string_to_State(textBox1->Text);
			 State goal = string_to_State(textBox2->Text);

			 if ((start.size() != 0)&&(goal.size() != 0)){

			 update_buttons(start);

			 if (is_solvable(start,goal)){
				 
				 dataGridView1->Rows->Clear();
				 nodes_reached = 0;
				 nodes_expanded = 0;
				 label3->Visible = true;
				 
				 this->Update();

				 p_optimal_path =  bidirectional_Astar(start,goal,0); // run bidirectional A*->Manhatten 
				 array<String^>^row1 = {"bidirectional MH",nodes_reached.ToString(),nodes_expanded.ToString(),p_optimal_path.size().ToString()};
				 dataGridView1->Rows->Add(row1);

				 this->Update();
				 dataGridView1->Update();
				 this->Update();

				 p_optimal_path =  Astar(start,goal,0); // run A*->Manhatten
				 array<String^>^row2 = {"Manhattan",nodes_reached.ToString(),nodes_expanded.ToString(),p_optimal_path.size().ToString()};
				 dataGridView1->Rows->Add(row2);
				
				 this->Update();
				 dataGridView1->Update();
				 this->Update();
		 
				 p_optimal_path = bidirectional_Astar(start,goal,1);
				 array<String^>^row3 = {"bidirectional Displ.",nodes_reached.ToString(),nodes_expanded.ToString(),p_optimal_path.size().ToString()};
				 dataGridView1->Rows->Add(row3);
				
				 this->Update();
				 dataGridView1->Update();
				 this->Update();

				 p_optimal_path = Astar(start,goal,1);
				 array<String^>^row4 = {"Displaced",nodes_reached.ToString(),nodes_expanded.ToString(),p_optimal_path.size().ToString()};
				 dataGridView1->Rows->Add(row4);
				
				 this->Update();
				 dataGridView1->Update();
				 this->Update();

				 p_optimal_path =  bidirectional_Astar(start,goal,2); // run bidirectional A*->h=0
				 array<String^>^row5 = {"bidirectional h=0",nodes_reached.ToString(),nodes_expanded.ToString(),p_optimal_path.size().ToString()};
				 dataGridView1->Rows->Add(row5);
				
				 this->Update();
				 dataGridView1->Update();
				 this->Update();

				 p_optimal_path = Astar(start,goal,2);
				 array<String^>^row6 = {"h=0",nodes_reached.ToString(),nodes_expanded.ToString(),p_optimal_path.size().ToString()};
				 dataGridView1->Rows->Add(row6);			 

				 p_current_state=0;

				 if (p_optimal_path.size() != 1) // if longer than 1
					button12->Enabled = true;

				 label3->Visible = false;
			 }
			 else
				 MessageBox::Show("This start-goal combination ist not solvable!","Please try again!");
			 }
		}

private: State string_to_State(String^ s){
			 int a[] = {0,0,0,0,0,0,0,0,0};
			 for (int i=0; i<9; i++){
				 a[i] = s[i*2]-48; // ugly but works --> char (ascii) to int
				 if ((a[i] < 0)||(a[i] > 9)){ // wrong user-input
					MessageBox::Show("There is something wrong with your input.\n Please try again!","Oh no!");
					State state;
					state.empty();
					return state;
				 }
			 }
			 State state(a,a+9);
			 return state;
		 }

private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) {			 
			p_current_state++;
			update_buttons(p_optimal_path[p_current_state]);
			button11->Enabled = true;

			if ((p_current_state+1) == p_optimal_path.size()) // end of optimal_path?
				button12->Enabled = false;
		 }
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {
			p_current_state--;
			update_buttons(p_optimal_path[p_current_state]);
			button12->Enabled = true;

			if ((p_current_state) == 0) // beginning of optimal_path?
				button11->Enabled = false;
		 }
};


}
