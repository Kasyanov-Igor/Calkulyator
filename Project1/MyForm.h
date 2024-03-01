#pragma once

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
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
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button1;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(0, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(50, 83);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(206, 20);
			this->textBox1->TabIndex = 1;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::SystemColors::WindowFrame;
			this->textBox2->Location = System::Drawing::Point(308, 83);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(166, 20);
			this->textBox2->TabIndex = 2;
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::SystemColors::Info;
			this->textBox3->ForeColor = System::Drawing::SystemColors::InactiveCaptionText;
			this->textBox3->Location = System::Drawing::Point(527, 83);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(126, 20);
			this->textBox3->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button1->Location = System::Drawing::Point(130, 216);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(493, 200);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Результат";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(784, 542);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->textBox3);
			this->Name = L"MyForm";
			this->Text = L"Калькулятор";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		template<typename B>
		B Plus(B a, B b)
		{
			return a + b;
		}
		template<typename B>
		B Minus(B a, B b)
		{
			return a - b;
		}
		template<typename B>
		B Umnosh(B a,B b)
		{
			return a * b;
		}
		template<typename B>
		B Deli(B a, B b)
		{
			return a / b;
		}

		int Step(int num_1, int num_2)
		{
			if (num_2 == 1)
			{
				return num_1;
			}
			return num_1 * Step(num_1, num_2 - 1);
		}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		double a = System::Convert::ToDouble(textBox1->Text);
		double b = System::Convert::ToDouble(textBox3->Text);
		char sw = System::Convert::ToChar(textBox2->Text);
		double resalt=0;
		switch (sw)

		{
		case '+':
		{
			resalt = Plus(a, b);
			break;
		}
		case '-':
		{
			resalt = Minus(a, b);
			break;
		}
		case '*':
		{
			resalt = Umnosh(a, b);
			break;
		}
		case '/':
		{
			resalt = Deli(a, b);
			break;
		}
		case '^':
		{
			resalt = Step(a, b);
			break;
		}
		}
		MessageBox::Show(System::Convert::ToString(resalt),
			"Результат:", MessageBoxButtons::OKCancel,
			MessageBoxIcon::Asterisk);

		
	}
};
}
