#include "MyForm.h"
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <set>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();

	JhonsonModel::MyForm form; 
	Application::Run(% form);
}

std::vector<std::vector<int>> data;
std::vector<int> seq;

void JhonsonModel::MyForm::Header(DataGridView^ dgv)
{
	dgv->Columns->Clear();
	int colWidth = 70;
	int idColWidth = 35;
	DataGridViewTextBoxColumn^ c0 = gcnew DataGridViewTextBoxColumn();
	c0->HeaderText = "ID";
	c0->Width = idColWidth;
	c0->SortMode = DataGridViewColumnSortMode::NotSortable();
	dgv->Columns->Add(c0);

	DataGridViewTextBoxColumn^ c1 = gcnew DataGridViewTextBoxColumn();
	c1->Width = colWidth;
	c1->HeaderText = "A";
	c1->SortMode = DataGridViewColumnSortMode::NotSortable();
	dgv->Columns->Add(c1);

	DataGridViewTextBoxColumn^ c2 = gcnew DataGridViewTextBoxColumn();
	c2->Width = colWidth;
	c2->HeaderText = "B";
	c2->SortMode = DataGridViewColumnSortMode::NotSortable();
	dgv->Columns->Add(c2);

	if (radioButton_3->Checked) {
		DataGridViewTextBoxColumn^ c3 = gcnew DataGridViewTextBoxColumn();
		c3->Width = colWidth;
		c3->HeaderText = "C";
		c3->SortMode = DataGridViewColumnSortMode::NotSortable();
		dgv->Columns->Add(c3);
	}
}

void JhonsonModel::MyForm::Show(DataGridView^ dgv)
{
	for (int i = 0; i < data.size(); i++) {
		dgv->Rows[i]->Cells[0]->Value = seq[i];
		dgv->Rows[i]->Cells[1]->Value = data[i][0];
		dgv->Rows[i]->Cells[2]->Value = data[i][1];
		if (radioButton_3->Checked)
			dgv->Rows[i]->Cells[3]->Value = data[i][2];
	}
}

void JhonsonModel::MyForm::Update(DataGridView^ dgv)
{
	dgv->Rows->Clear();

	dgv->RowCount = data.size();
	dgv->ColumnCount = radioButton_3->Checked ? 4 : 3;
	Show(dgv);

	dgv->AutoResizeRowHeadersWidth(DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders);
	dgv->AutoResizeRows();
}

const int sizePictureBox = 10;
const int defaultY = 20;
const int yOffset = 35;
const int pbXoffset = 5;

void JhonsonModel::MyForm::PaintDiagram(Panel^ panel, Label^ time)
{
	int totalTime = 0;

	panel->Controls->Clear();
	int x = 10;
	int itA = 0;
	for (int i = 0; i < data.size(); i++) {
		int numA = data[i][0];
		DrawStrip(x, defaultY, numA, "a", itA, panel);
	}

	x = 10;
	int itB = 0, itX = 0;
	int X = data[0][0]; 
	int yB = defaultY + yOffset;
	for (int i = 0; i < data.size(); i++) {
		int numB = data[i][1];
		totalTime += (numB + std::max(X, 0));
		// draw X
		DrawStrip(x, yB, X, "x", itX, panel);
		if (i + 1 < data.size()) {
			int tempX = std::max(X, 0);
			X += data[i + 1][0] - data[i][1] - tempX; // X(n) = A(n) - B(n - 1)
		}
		// draw B
		DrawStrip(x, yB, numB, "b", itB, panel);
	}

	if (radioButton_3->Checked) {
		totalTime = 0;
		x = 10;
		int itC = 0, itY = 0;
		int Y = data[0][0] + data[0][1];
		yB += yOffset;
		for (int i = 0; i < data.size(); i++) {
			int numC = data[i][2];
			totalTime += (numC + std::max(Y, 0));
			// draw Y
			DrawStrip(x, yB, Y, "y", itY, panel);
			if (i + 1 < data.size()) {
				int tempY = std::max(Y, 0);
				int tempX = std::max(X, 0);
				X += data[i + 1][0] - data[i][1] - tempX;		// X(n) = A(n) - B(n - 1)
				Y += data[i + 1][1] - data[i][2] - tempY + X;	// Y(n) = B(n) - C(n - 1)
			}
			// draw C
			DrawStrip(x, yB, numC, "c", itC, panel);
		}
	}

	time->Text = "T(S): " + totalTime;
}

void JhonsonModel::MyForm::DrawStrip(int &startX, int startY, int num, String^ ch, int &numInSeq, Panel^ panel)
{
	array<Color>^ colors = { Color::Red, Color::Blue, Color::Green, Color::Orange, Color::Purple };
	Color currColor = ch == "x" || ch == "y" ? Color::Yellow : colors[seq[numInSeq] % colors->Length];
	String^ lb = ch == "x" || ch == "y" ? ch + numInSeq : ch + seq[numInSeq];
	if (num > 0) numInSeq++;
	int middle = num / 2;
	while (num-- > 0) {
		if (num == middle) createLb(startX, startY, lb, panel);
		createPB(startX, startY, currColor, panel);
		startX += sizePictureBox + pbXoffset;
	}
}

void JhonsonModel::MyForm::createPB(int x, int y, Color color, Panel^ panel)
{
	PictureBox^ pb = gcnew PictureBox();
	pb->Size = Drawing::Size(sizePictureBox, sizePictureBox);
	pb->Location = Drawing::Point(x, y);
	pb->BackColor = color;
	panel->Controls->Add(pb);
}

void JhonsonModel::MyForm::createLb(int x, int y, String^ str, Panel^ panel)
{
	Label^ lb = gcnew Label();
	lb->Text = str;
	lb->Size = Drawing::Size(25, 20);
	lb->Font = gcnew Drawing::Font("Microsoft Sans Serif", 9);
	lb->Location = Drawing::Point(x - 5, y - 20);
	panel->Controls->Add(lb);
}

std::vector<int> JhonsonModel::MyForm::Johnson()
{
	std::vector<int> id(data.size());
	for (int i = 0; i < id.size(); i++) id[i] = i;

	std::vector<bool> visited(data.size(), false);
	for (int i = 0; i < data.size(); i++) {
		std::pair<int, int> min = minInData(visited);
		if (min.first == -2) break;
		else {
			// swap if A is min
			if (min.first == -1) {
				for (int i = 0; i < data.size(); i++) {
					if (i != min.second && !visited[i]) {
						std::swap(data[i], data[min.second]);
						std::swap(id[i], id[min.second]);
						visited[i] = true;
						break;
					}
				}
			}
			// swap if B is min
			else if (min.first == 1) {
				for (int i = data.size() - 1; i >= 0; i--) {
					if (!visited[i]) {
						std::swap(data[i], data[min.second]);
						std::swap(id[i], id[min.second]);
						visited[i] = true;
						break;
					}
				}
			}
		}
	}

	return id;
}

std::vector<int> JhonsonModel::MyForm::Enum2()
{
	std::vector<int> id(data.size()), minId;
	for (int i = 0; i < id.size(); i++) id[i] = i;
	minId = id;

	int minimalX = -1; 
	while (nextSet(id)) {
		int currX = data[id[0]][0], sumX = 0;
		for (int i = 0; i < id.size(); i++) {
			int tempX = std::max(currX, 0);
			sumX += tempX;
			if (i + 1 < data.size())
				currX += data[id[i + 1]][0] - data[id[i]][1] - tempX;
		}

		if (minimalX == -1 || sumX < minimalX) {
			minimalX = sumX;
			minId = id;
		}
		
	}
	return minId;
}

std::vector<int> JhonsonModel::MyForm::Enum3()
{
	std::vector<int> id(data.size()), minId;
	for (int i = 0; i < id.size(); i++) id[i] = i;
	minId = id;

	int minimalY = -1;
	while (nextSet(id)) {
		int currX = data[id[0]][0], currY = data[id[0]][0] + data[id[0]][1], sumY = 0;
		for (int i = 0; i < id.size(); i++) {
			int tempY = std::max(currY, 0), tempX = std::max(currX, 0);
			sumY += tempY;
			if (i + 1 < data.size()) {
				currX += data[id[i + 1]][0] - data[id[i]][1] - tempX;
				currY += data[id[i + 1]][1] - data[id[i]][2] - tempY + currX;
			}
		}

		if (minimalY == -1 ||sumY < minimalY) {
			minimalY = sumY;
			minId = id;
		}	
	}

	return minId;
}

bool JhonsonModel::MyForm::nextSet(std::vector<int>& a)
{
	int n = a.size();
	int j = n - 2;
	while (j != -1 && a[j] >= a[j + 1]) j--;
	if (j == -1)
		return false; // больше перестановок нет 
	int k = n - 1;
	while (a[j] >= a[k]) k--;
	std::swap(a[j],a[k]);
	int l = j + 1, r = n - 1; // сортируем оставшуюся часть последовательности 
	while (l < r)
		std::swap(a[l++], a[r--]);
	return true;
}

std::pair<int, int> JhonsonModel::MyForm::minInData(std::vector<bool>& visited)
{
	int index = -1;
	for (int i = 0; i < visited.size(); i++) {
		if (!visited[i]) {
			index = i;
			break;
		}
	}
	if (index == -1) return { -2, -2 };

	int minNum = data[index][0], side = 0;
	for (int i = 0; i < data.size(); i++) {
		if (!visited[i]) {
			if (data[i][0] < minNum) {
				minNum = data[i][0];
				index = i;
				side = -1;
			}
			if (data[i][1] < minNum) {
				minNum = data[i][1];
				index = i;
				side = 1;
			}
		}
	}
	return { side, index };
}

bool JhonsonModel::MyForm::checkCondition()
{
	int minA = data[0][0], maxB = data[0][1], minC = data[0][2];
	for (int i = 0; i < data.size(); i++) {
		minA = std::min(minA, data[i][0]);
		maxB = std::max(maxB, data[i][1]);
		minC = std::min(minC, data[i][2]);
	}
	return (minA >= maxB || maxB <= minC);
}

void JhonsonModel::MyForm::Solve()
{
	if (radioButton_3->Checked) label_condition->Visible = true;
	else label_condition->Visible = false;

	if (radioButton_3->Checked && !checkCondition()) {
		label_condition->ForeColor = Color::Red;
		label_condition->Text = "Condition is not satisfed!";
		if (radioButton_johnson->Checked) {
			dataGridView_after->Columns->Clear();
			panel_after->Controls->Clear();
			return;
		}
	}
	else {
		label_condition->ForeColor = Color::Green;
		label_condition->Text = "Condition is satisfed!";
	}

	std::vector<std::vector<int>> memorize = data;
	if (radioButton_johnson->Checked) {
		
		std::vector<std::vector<int>> temp = data;
		if (radioButton_3->Checked) {
			for (int i = 0; i < data.size(); i++) {
				data[i][0] += data[i][1];
				data[i][1] += data[i][2];
			}
		}
		seq = Johnson();

		for (int i = 0; i < seq.size(); i++)
			data[i] = temp[seq[i]];
		
	}
	else {
		// get best sequences
		if (radioButton_3->Checked) seq = Enum3();
		else seq = Enum2();
		std::vector<std::vector<int>> temp(data.size());
		int i = 0;
		for (auto it : seq) temp[i++] = data[it];
		data = temp;
	}

	Header(dataGridView_after);
	Update(dataGridView_after);
	PaintDiagram(panel_after, label_timeAfter);

	data = memorize;
}

System::Void JhonsonModel::MyForm::radioButton_2_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	MyForm_Load(sender, e);
}

System::Void JhonsonModel::MyForm::MyForm_Load(System::Object^ sender, System::EventArgs^ e)
{
	data.clear();
	// Read 
	std::ifstream file;
	if (radioButton_2->Checked) file.open("data.txt");
	else file.open("data3.txt");

	std::string line;
	while (std::getline(file, line)) {
		std::istringstream iss(line);
		std::vector<int> row;
		int num;
		while (iss >> num) {
			row.push_back(num);
		}
		data.push_back(row);
	}
	file.close();

	seq.resize(data.size());
	for (int i = 0; i < seq.size(); i++) seq[i] = i;

	Header(dataGridView_before);
	Update(dataGridView_before);
	PaintDiagram(panel_before, label_timeBefore);

	Solve();
}

System::Void JhonsonModel::MyForm::radioButton_johnson_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
{
	Solve();
}
