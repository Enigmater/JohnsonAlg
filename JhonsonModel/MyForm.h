#pragma once
#include <utility>
#include <vector>

namespace JhonsonModel {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView_before;
	protected:
	private: System::Windows::Forms::DataGridView^ dataGridView_after;
	private: System::Windows::Forms::Label^ label_dataBefore;
	private: System::Windows::Forms::Label^ label_dataAfter;


	private: System::Windows::Forms::Panel^ panel_left;
	private: System::Windows::Forms::Panel^ panel_right;
	private: System::Windows::Forms::Panel^ panel_before;
	private: System::Windows::Forms::Panel^ panel_after;
	private: System::Windows::Forms::Panel^ panel_settings;
	private: System::Windows::Forms::Panel^ panel_numOfMachine;
	private: System::Windows::Forms::Panel^ panel_mode;
	private: System::Windows::Forms::RadioButton^ radioButton_johnson;
	private: System::Windows::Forms::RadioButton^ radioButton_3;
	private: System::Windows::Forms::RadioButton^ radioButton_2;
	private: System::Windows::Forms::RadioButton^ radioButton_enumeration;
	private: System::Windows::Forms::Label^ label_timeAfter;
	private: System::Windows::Forms::Label^ label_timeBefore;
	private: System::Windows::Forms::Label^ label_condition;





	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->dataGridView_before = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridView_after = (gcnew System::Windows::Forms::DataGridView());
			this->label_dataBefore = (gcnew System::Windows::Forms::Label());
			this->label_dataAfter = (gcnew System::Windows::Forms::Label());
			this->panel_left = (gcnew System::Windows::Forms::Panel());
			this->label_timeAfter = (gcnew System::Windows::Forms::Label());
			this->label_timeBefore = (gcnew System::Windows::Forms::Label());
			this->panel_right = (gcnew System::Windows::Forms::Panel());
			this->panel_after = (gcnew System::Windows::Forms::Panel());
			this->panel_before = (gcnew System::Windows::Forms::Panel());
			this->panel_settings = (gcnew System::Windows::Forms::Panel());
			this->panel_mode = (gcnew System::Windows::Forms::Panel());
			this->radioButton_enumeration = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_johnson = (gcnew System::Windows::Forms::RadioButton());
			this->panel_numOfMachine = (gcnew System::Windows::Forms::Panel());
			this->radioButton_3 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_2 = (gcnew System::Windows::Forms::RadioButton());
			this->label_condition = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_before))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_after))->BeginInit();
			this->panel_left->SuspendLayout();
			this->panel_right->SuspendLayout();
			this->panel_settings->SuspendLayout();
			this->panel_mode->SuspendLayout();
			this->panel_numOfMachine->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView_before
			// 
			this->dataGridView_before->AllowUserToAddRows = false;
			this->dataGridView_before->AllowUserToDeleteRows = false;
			this->dataGridView_before->ColumnHeadersHeight = 30;
			this->dataGridView_before->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->dataGridView_before->Location = System::Drawing::Point(10, 30);
			this->dataGridView_before->Margin = System::Windows::Forms::Padding(6);
			this->dataGridView_before->Name = L"dataGridView_before";
			this->dataGridView_before->ReadOnly = true;
			this->dataGridView_before->RowHeadersVisible = false;
			this->dataGridView_before->Size = System::Drawing::Size(357, 184);
			this->dataGridView_before->TabIndex = 0;
			// 
			// dataGridView_after
			// 
			this->dataGridView_after->AllowUserToAddRows = false;
			this->dataGridView_after->AllowUserToDeleteRows = false;
			this->dataGridView_after->ColumnHeadersHeight = 30;
			this->dataGridView_after->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::DisableResizing;
			this->dataGridView_after->Location = System::Drawing::Point(10, 255);
			this->dataGridView_after->Margin = System::Windows::Forms::Padding(6);
			this->dataGridView_after->Name = L"dataGridView_after";
			this->dataGridView_after->ReadOnly = true;
			this->dataGridView_after->RowHeadersVisible = false;
			this->dataGridView_after->Size = System::Drawing::Size(357, 184);
			this->dataGridView_after->TabIndex = 1;
			// 
			// label_dataBefore
			// 
			this->label_dataBefore->AutoSize = true;
			this->label_dataBefore->Location = System::Drawing::Point(10, 6);
			this->label_dataBefore->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label_dataBefore->Name = L"label_dataBefore";
			this->label_dataBefore->Size = System::Drawing::Size(81, 25);
			this->label_dataBefore->TabIndex = 2;
			this->label_dataBefore->Text = L"Before:";
			// 
			// label_dataAfter
			// 
			this->label_dataAfter->AutoSize = true;
			this->label_dataAfter->Location = System::Drawing::Point(10, 231);
			this->label_dataAfter->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label_dataAfter->Name = L"label_dataAfter";
			this->label_dataAfter->Size = System::Drawing::Size(63, 25);
			this->label_dataAfter->TabIndex = 3;
			this->label_dataAfter->Text = L"After:";
			// 
			// panel_left
			// 
			this->panel_left->Controls->Add(this->label_condition);
			this->panel_left->Controls->Add(this->label_timeAfter);
			this->panel_left->Controls->Add(this->label_timeBefore);
			this->panel_left->Controls->Add(this->dataGridView_before);
			this->panel_left->Controls->Add(this->dataGridView_after);
			this->panel_left->Controls->Add(this->label_dataAfter);
			this->panel_left->Controls->Add(this->label_dataBefore);
			this->panel_left->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel_left->Location = System::Drawing::Point(0, 0);
			this->panel_left->Name = L"panel_left";
			this->panel_left->Size = System::Drawing::Size(380, 585);
			this->panel_left->TabIndex = 5;
			// 
			// label_timeAfter
			// 
			this->label_timeAfter->AutoSize = true;
			this->label_timeAfter->Location = System::Drawing::Point(177, 445);
			this->label_timeAfter->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label_timeAfter->Name = L"label_timeAfter";
			this->label_timeAfter->Size = System::Drawing::Size(65, 25);
			this->label_timeAfter->TabIndex = 8;
			this->label_timeAfter->Text = L"T(S): ";
			// 
			// label_timeBefore
			// 
			this->label_timeBefore->AutoSize = true;
			this->label_timeBefore->Location = System::Drawing::Point(177, 224);
			this->label_timeBefore->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label_timeBefore->Name = L"label_timeBefore";
			this->label_timeBefore->Size = System::Drawing::Size(59, 25);
			this->label_timeBefore->TabIndex = 4;
			this->label_timeBefore->Text = L"T(S):";
			// 
			// panel_right
			// 
			this->panel_right->Controls->Add(this->panel_after);
			this->panel_right->Controls->Add(this->panel_before);
			this->panel_right->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel_right->Location = System::Drawing::Point(380, 0);
			this->panel_right->Name = L"panel_right";
			this->panel_right->Size = System::Drawing::Size(768, 585);
			this->panel_right->TabIndex = 6;
			// 
			// panel_after
			// 
			this->panel_after->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel_after->Location = System::Drawing::Point(17, 244);
			this->panel_after->Name = L"panel_after";
			this->panel_after->Size = System::Drawing::Size(739, 184);
			this->panel_after->TabIndex = 7;
			// 
			// panel_before
			// 
			this->panel_before->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->panel_before->Location = System::Drawing::Point(17, 30);
			this->panel_before->Name = L"panel_before";
			this->panel_before->Size = System::Drawing::Size(739, 184);
			this->panel_before->TabIndex = 6;
			// 
			// panel_settings
			// 
			this->panel_settings->Controls->Add(this->panel_mode);
			this->panel_settings->Controls->Add(this->panel_numOfMachine);
			this->panel_settings->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel_settings->Location = System::Drawing::Point(0, 585);
			this->panel_settings->Name = L"panel_settings";
			this->panel_settings->Size = System::Drawing::Size(1148, 109);
			this->panel_settings->TabIndex = 8;
			// 
			// panel_mode
			// 
			this->panel_mode->Controls->Add(this->radioButton_enumeration);
			this->panel_mode->Controls->Add(this->radioButton_johnson);
			this->panel_mode->Location = System::Drawing::Point(198, 9);
			this->panel_mode->Name = L"panel_mode";
			this->panel_mode->Size = System::Drawing::Size(169, 88);
			this->panel_mode->TabIndex = 1;
			// 
			// radioButton_enumeration
			// 
			this->radioButton_enumeration->AutoSize = true;
			this->radioButton_enumeration->Location = System::Drawing::Point(3, 38);
			this->radioButton_enumeration->Name = L"radioButton_enumeration";
			this->radioButton_enumeration->Size = System::Drawing::Size(151, 29);
			this->radioButton_enumeration->TabIndex = 3;
			this->radioButton_enumeration->Text = L"Enumeration";
			this->radioButton_enumeration->UseVisualStyleBackColor = true;
			// 
			// radioButton_johnson
			// 
			this->radioButton_johnson->AutoSize = true;
			this->radioButton_johnson->Checked = true;
			this->radioButton_johnson->Location = System::Drawing::Point(3, 3);
			this->radioButton_johnson->Name = L"radioButton_johnson";
			this->radioButton_johnson->Size = System::Drawing::Size(112, 29);
			this->radioButton_johnson->TabIndex = 2;
			this->radioButton_johnson->TabStop = true;
			this->radioButton_johnson->Text = L"Johnson";
			this->radioButton_johnson->UseVisualStyleBackColor = true;
			this->radioButton_johnson->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton_johnson_CheckedChanged);
			// 
			// panel_numOfMachine
			// 
			this->panel_numOfMachine->Controls->Add(this->radioButton_3);
			this->panel_numOfMachine->Controls->Add(this->radioButton_2);
			this->panel_numOfMachine->Location = System::Drawing::Point(10, 9);
			this->panel_numOfMachine->Name = L"panel_numOfMachine";
			this->panel_numOfMachine->Size = System::Drawing::Size(169, 88);
			this->panel_numOfMachine->TabIndex = 0;
			// 
			// radioButton_3
			// 
			this->radioButton_3->AutoSize = true;
			this->radioButton_3->Location = System::Drawing::Point(3, 38);
			this->radioButton_3->Name = L"radioButton_3";
			this->radioButton_3->Size = System::Drawing::Size(140, 29);
			this->radioButton_3->TabIndex = 1;
			this->radioButton_3->Text = L"3 machines";
			this->radioButton_3->UseVisualStyleBackColor = true;
			// 
			// radioButton_2
			// 
			this->radioButton_2->AutoSize = true;
			this->radioButton_2->Checked = true;
			this->radioButton_2->Location = System::Drawing::Point(3, 3);
			this->radioButton_2->Name = L"radioButton_2";
			this->radioButton_2->Size = System::Drawing::Size(140, 29);
			this->radioButton_2->TabIndex = 0;
			this->radioButton_2->TabStop = true;
			this->radioButton_2->Text = L"2 machines";
			this->radioButton_2->UseVisualStyleBackColor = true;
			this->radioButton_2->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton_2_CheckedChanged);
			// 
			// label_condition
			// 
			this->label_condition->AutoSize = true;
			this->label_condition->Location = System::Drawing::Point(10, 475);
			this->label_condition->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->label_condition->Name = L"label_condition";
			this->label_condition->Size = System::Drawing::Size(63, 25);
			this->label_condition->TabIndex = 9;
			this->label_condition->Text = L"Cond";
			this->label_condition->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1148, 694);
			this->Controls->Add(this->panel_right);
			this->Controls->Add(this->panel_left);
			this->Controls->Add(this->panel_settings);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_before))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_after))->EndInit();
			this->panel_left->ResumeLayout(false);
			this->panel_left->PerformLayout();
			this->panel_right->ResumeLayout(false);
			this->panel_settings->ResumeLayout(false);
			this->panel_mode->ResumeLayout(false);
			this->panel_mode->PerformLayout();
			this->panel_numOfMachine->ResumeLayout(false);
			this->panel_numOfMachine->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	// DataGridView helpers
	private: void Header(DataGridView^ dgv);
	private: void Show(DataGridView^ dgv);
	private: void Update(DataGridView^ dgv);

	//  Draw diagram
	private: void PaintDiagram(Panel^ panel, Label^ time);
	private: void DrawStrip(int &startX, int startY, int num, String^ ch, int &numInSeq, Panel^ panel);
	private: void createPB(int x, int y, Color color, Panel^ panel);
	private: void createLb(int x, int y, String^ str, Panel^ panel);

	// Algorithms
	private: std::vector<int> Johnson();
	private: std::pair<int, int> minInData(std::vector<bool>& visited);
	private: bool checkCondition();
	private: std::vector<int> Enum2();
	private: std::vector<int> Enum3();
	private: bool nextSet(std::vector<int>& a);

	// Events
	private: void Solve();
	private: System::Void radioButton_2_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e);
	private: System::Void radioButton_johnson_CheckedChanged(System::Object^ sender, System::EventArgs^ e);
};
}
