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
	/// Summary for Form_Cannibals
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form_Cannibals : public System::Windows::Forms::Form
	{
	public:
		Form_Cannibals(void)
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
		~Form_Cannibals()
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
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Button^  button12;
	private: System::Windows::Forms::Button^  button13;
	private: System::Windows::Forms::Button^  button14;
	private: System::Windows::Forms::Button^  button15;
	private: System::Windows::Forms::Button^  button16;
	private: System::Windows::Forms::Button^  button17;
	private: System::Windows::Forms::Button^  button18;
	private: System::Windows::Forms::Button^  button19;
	private: System::Windows::Forms::Button^  button20;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Panel^  panel2;




	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button25;
	private: System::Windows::Forms::Button^  button26;
	private: System::Windows::Forms::Button^  button27;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Panel^  panel3;



	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  type;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  baseline;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  heu;





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
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button16 = (gcnew System::Windows::Forms::Button());
			this->button17 = (gcnew System::Windows::Forms::Button());
			this->button18 = (gcnew System::Windows::Forms::Button());
			this->button19 = (gcnew System::Windows::Forms::Button());
			this->button20 = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->type = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->baseline = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->heu = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button25 = (gcnew System::Windows::Forms::Button());
			this->button26 = (gcnew System::Windows::Forms::Button());
			this->button27 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
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
			this->button1->Size = System::Drawing::Size(30, 30);
			this->button1->TabIndex = 0;
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(48, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(30, 30);
			this->button2->TabIndex = 1;
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(84, 12);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(30, 30);
			this->button3->TabIndex = 2;
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(120, 12);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(30, 30);
			this->button4->TabIndex = 3;
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button5->Location = System::Drawing::Point(156, 12);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(30, 30);
			this->button5->TabIndex = 4;
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button6->Location = System::Drawing::Point(192, 12);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(30, 30);
			this->button6->TabIndex = 5;
			this->button6->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button7->Location = System::Drawing::Point(228, 12);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(30, 30);
			this->button7->TabIndex = 6;
			this->button7->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button8->Location = System::Drawing::Point(264, 12);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(30, 30);
			this->button8->TabIndex = 7;
			this->button8->UseVisualStyleBackColor = true;
			// 
			// button9
			// 
			this->button9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button9->Location = System::Drawing::Point(300, 12);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(30, 30);
			this->button9->TabIndex = 8;
			this->button9->UseVisualStyleBackColor = true;
			// 
			// button10
			// 
			this->button10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button10->Location = System::Drawing::Point(336, 12);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(30, 30);
			this->button10->TabIndex = 9;
			this->button10->UseVisualStyleBackColor = true;
			// 
			// button11
			// 
			this->button11->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button11->Location = System::Drawing::Point(336, 181);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(30, 30);
			this->button11->TabIndex = 19;
			this->button11->UseVisualStyleBackColor = true;
			// 
			// button12
			// 
			this->button12->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button12->Location = System::Drawing::Point(300, 181);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(30, 30);
			this->button12->TabIndex = 18;
			this->button12->UseVisualStyleBackColor = true;
			// 
			// button13
			// 
			this->button13->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button13->Location = System::Drawing::Point(264, 181);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(30, 30);
			this->button13->TabIndex = 17;
			this->button13->UseVisualStyleBackColor = true;
			// 
			// button14
			// 
			this->button14->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button14->Location = System::Drawing::Point(228, 181);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(30, 30);
			this->button14->TabIndex = 16;
			this->button14->UseVisualStyleBackColor = true;
			// 
			// button15
			// 
			this->button15->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button15->Location = System::Drawing::Point(192, 181);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(30, 30);
			this->button15->TabIndex = 15;
			this->button15->UseVisualStyleBackColor = true;
			// 
			// button16
			// 
			this->button16->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button16->Location = System::Drawing::Point(156, 181);
			this->button16->Name = L"button16";
			this->button16->Size = System::Drawing::Size(30, 30);
			this->button16->TabIndex = 14;
			this->button16->UseVisualStyleBackColor = true;
			// 
			// button17
			// 
			this->button17->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button17->Location = System::Drawing::Point(120, 181);
			this->button17->Name = L"button17";
			this->button17->Size = System::Drawing::Size(30, 30);
			this->button17->TabIndex = 13;
			this->button17->UseVisualStyleBackColor = true;
			// 
			// button18
			// 
			this->button18->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button18->Location = System::Drawing::Point(84, 181);
			this->button18->Name = L"button18";
			this->button18->Size = System::Drawing::Size(30, 30);
			this->button18->TabIndex = 12;
			this->button18->UseVisualStyleBackColor = true;
			// 
			// button19
			// 
			this->button19->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button19->Location = System::Drawing::Point(48, 181);
			this->button19->Name = L"button19";
			this->button19->Size = System::Drawing::Size(30, 30);
			this->button19->TabIndex = 11;
			this->button19->UseVisualStyleBackColor = true;
			// 
			// button20
			// 
			this->button20->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button20->Location = System::Drawing::Point(12, 181);
			this->button20->Name = L"button20";
			this->button20->Size = System::Drawing::Size(30, 30);
			this->button20->TabIndex = 10;
			this->button20->UseVisualStyleBackColor = true;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::Highlight;
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Location = System::Drawing::Point(12, 48);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(354, 127);
			this->panel1->TabIndex = 20;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panel3->Location = System::Drawing::Point(97, 85);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(149, 39);
			this->panel3->TabIndex = 22;
			this->panel3->Visible = false;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panel2->Location = System::Drawing::Point(97, 3);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(149, 39);
			this->panel2->TabIndex = 21;
			this->panel2->Visible = false;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {this->type, this->baseline, 
				this->heu});
			this->dataGridView1->Location = System::Drawing::Point(412, 13);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->Size = System::Drawing::Size(353, 198);
			this->dataGridView1->TabIndex = 21;
			// 
			// type
			// 
			this->type->HeaderText = L"";
			this->type->Name = L"type";
			this->type->ReadOnly = true;
			// 
			// baseline
			// 
			this->baseline->HeaderText = L"# reached nodes";
			this->baseline->Name = L"baseline";
			this->baseline->ReadOnly = true;
			this->baseline->Width = 110;
			// 
			// heu
			// 
			this->heu->HeaderText = L"# expanded nodes";
			this->heu->Name = L"heu";
			this->heu->ReadOnly = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 237);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(74, 13);
			this->label1->TabIndex = 22;
			this->label1->Text = L"# Missionaries";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 264);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(63, 13);
			this->label2->TabIndex = 23;
			this->label2->Text = L"# Cannibals";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(92, 234);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(22, 20);
			this->textBox1->TabIndex = 24;
			this->textBox1->Text = L"5";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(92, 261);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(22, 20);
			this->textBox2->TabIndex = 25;
			this->textBox2->Text = L"4";
			// 
			// button25
			// 
			this->button25->Location = System::Drawing::Point(156, 259);
			this->button25->Name = L"button25";
			this->button25->Size = System::Drawing::Size(75, 23);
			this->button25->TabIndex = 26;
			this->button25->Text = L"Solve!";
			this->button25->UseVisualStyleBackColor = true;
			this->button25->Click += gcnew System::EventHandler(this, &Form_Cannibals::button25_Click);
			// 
			// button26
			// 
			this->button26->Enabled = false;
			this->button26->Location = System::Drawing::Point(264, 259);
			this->button26->Name = L"button26";
			this->button26->Size = System::Drawing::Size(25, 23);
			this->button26->TabIndex = 27;
			this->button26->Text = L"<";
			this->button26->UseVisualStyleBackColor = true;
			this->button26->Click += gcnew System::EventHandler(this, &Form_Cannibals::button26_Click);
			// 
			// button27
			// 
			this->button27->Enabled = false;
			this->button27->Location = System::Drawing::Point(300, 259);
			this->button27->Name = L"button27";
			this->button27->Size = System::Drawing::Size(25, 23);
			this->button27->TabIndex = 28;
			this->button27->Text = L">";
			this->button27->UseVisualStyleBackColor = true;
			this->button27->Click += gcnew System::EventHandler(this, &Form_Cannibals::button27_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(92, 288);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(22, 20);
			this->textBox3->TabIndex = 30;
			this->textBox3->Text = L"3";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 291);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(73, 13);
			this->label3->TabIndex = 29;
			this->label3->Text = L"Boat-Capacity";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::Red;
			this->label4->Location = System::Drawing::Point(489, 261);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(229, 17);
			this->label4->TabIndex = 31;
			this->label4->Text = L"Please wait while calculating...";
			this->label4->Visible = false;
			// 
			// Form_Cannibals
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(787, 320);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button27);
			this->Controls->Add(this->button26);
			this->Controls->Add(this->button25);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button11);
			this->Controls->Add(this->button12);
			this->Controls->Add(this->button13);
			this->Controls->Add(this->button14);
			this->Controls->Add(this->button15);
			this->Controls->Add(this->button16);
			this->Controls->Add(this->button17);
			this->Controls->Add(this->button18);
			this->Controls->Add(this->button19);
			this->Controls->Add(this->button20);
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
			this->Controls->Add(this->panel1);
			this->Name = L"Form_Cannibals";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Cannibals & Missionaries";
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void button25_Click(System::Object^  sender, System::EventArgs^  e) {
			
			 button26->Enabled = false;
			 button27->Enabled = false;
			 
			 
			 int a[] = {0,0,0}; 
			
			 a[0] = textBox1->Text[0]-48; // # Missionaries
			 a[1] = textBox2->Text[0]-48; // # Cannibals
			 BOAT_SIZE = textBox3->Text[0]-48; // Boatcapacity


			 State start = c_make_state(a[0],a[1],1,a[0],a[1]);
			 State goal = c_make_state(0,0,0,a[0],a[1]);

			 if ((a[0] > 5) || (a[1] > 5) || (BOAT_SIZE > 4)){
				MessageBox::Show("Please choose \n  #Missionaries <= 5\n  #Cannibals <= 5\n  Boatcapacity <= 4","Please try again!");
				return;
			 }
			
			 update_buttons(start);

			 if (c_is_solvable(start,goal)){

				 dataGridView1->Rows->Clear();
				 nodes_reached = 0;
				 nodes_expanded = 0;
				 flag = 0;
				 label4->Visible = true;

				 this->Update();

				 c_optimal_path = c_Astar(start,goal,0);

				 array<String^>^row1 = {"heuristic",nodes_reached.ToString(),nodes_expanded.ToString()};
				 dataGridView1->Rows->Add(row1);

				 this->Update();
				 dataGridView1->Update();
				 this->Update();

				 c_Astar(start,goal,1);
				 array<String^>^row2 = {"h=0",nodes_reached.ToString(),nodes_expanded.ToString()};
				 dataGridView1->Rows->Add(row2);

				 this->Update();
				 dataGridView1->Update();
				 this->Update();

				 c_current_state=0;

				 if (c_optimal_path.size() != 1) // if longer than 1
					button27->Enabled = true;

				 label4->Visible = false;
			 }
			 else
				MessageBox::Show("There is no solution for combination of parameters.\nPlease try again!","Ooops");

		 }


private: void update_buttons(State state){
			 	
			array<System::String ^>^ upper_shore_m = gcnew array<System::String ^> {"","","","",""};
			array<System::String ^>^ upper_shore_c = gcnew array<System::String ^> {"","","","",""};
			array<System::String ^>^ lower_shore_m = gcnew array<System::String ^> {"","","","",""};
			array<System::String ^>^ lower_shore_c = gcnew array<System::String ^> {"","","","",""};

			// Upper Shore
			for (int i=0; i < state[0]; i++)
				upper_shore_m[i] = "M";

			for (int i=0; i < state[1]; i++)
				upper_shore_c[i] = "C";

			// Lower Shore
			for (int i=0; i < (state[3] - state[0]); i++) // number off original Missionaries - current Missionaries
				lower_shore_m[i] = "M";

			for (int i=0; i < (state[4] - state[1]); i++) // number off original Cannibals - current Cannibals
				lower_shore_c[i] = "C";

			// Upper Shore
			button1->Text = upper_shore_m[0];
			button2->Text = upper_shore_m[1];
			button3->Text = upper_shore_m[2];
			button4->Text = upper_shore_m[3];
			button5->Text = upper_shore_m[4];

			button6->Text = upper_shore_c[0];
			button7->Text = upper_shore_c[1];
			button8->Text = upper_shore_c[2];
			button9->Text = upper_shore_c[3];
			button10->Text = upper_shore_c[4];

			// Lower Shore
			button11->Text = lower_shore_m[0];
			button12->Text = lower_shore_m[1];
			button13->Text = lower_shore_m[2];
			button14->Text = lower_shore_m[3];
			button15->Text = lower_shore_m[4];

			button16->Text = lower_shore_c[0];
			button17->Text = lower_shore_c[1];
			button18->Text = lower_shore_c[2];
			button19->Text = lower_shore_c[3];
			button20->Text = lower_shore_c[4];

			// Boat
			if (state[2] == 0){
				panel3->Visible = true;
				panel2->Visible = false;
			}
			else{
				panel2->Visible = true;
				panel3->Visible = false;
			}

		 }

private: std::vector<State> cannibals(State state){
			 // replace by REAL CODE
				std::vector<State> answer;
				int a0[] = {3,3,0};
				int a1[] = {3,2,1};
				int a2[] = {1,1,0};
				State v0(a0,a0+9);
				State v1(a1,a1+9);
				State v2(a2,a2+9);
				answer.push_back(v0);
				answer.push_back(v1);
				answer.push_back(v2);
				return answer;
		 }

private: System::Void button26_Click(System::Object^  sender, System::EventArgs^  e) {
		    c_current_state--;
			update_buttons(c_optimal_path[c_current_state]);
			button27->Enabled = true;

			if ((c_current_state) == 0) // beginning of optimal_path?
				button26->Enabled = false;
		 }

private: System::Void button27_Click(System::Object^  sender, System::EventArgs^  e) {
			c_current_state++;
			update_buttons(c_optimal_path[c_current_state]);
			button26->Enabled = true;

			if ((c_current_state+1) == c_optimal_path.size()) // end of optimal_path?
				button27->Enabled = false;
		 }
private: System::Void button21_Click(System::Object^  sender, System::EventArgs^  e) {
			 panel2->Visible = !(panel2->Visible);
		 }
};
}
