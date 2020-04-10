
// CalculatorDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "afxdialogex.h"
#include "NumState.h"
#include "DotState.h"
#include "OpState.h"
#include <string>
#include "EqualsState.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCalculatorDlg 对话框



CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CALCULATOR_DIALOG, pParent),
	_leftValue('0'),_rightValue(),_op(' ')
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_RESULT_DISPLAY, _resultDisplay);
	DDX_Control(pDX, IDC_STATIC_SHOW, _show);
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ZERO, &CCalculatorDlg::OnBnClickedButtonZero)
	ON_BN_CLICKED(IDC_BUTTON_ONE, &CCalculatorDlg::OnBnClickedButtonOne)
	ON_BN_CLICKED(IDC_BUTTON_TWO, &CCalculatorDlg::OnBnClickedButtonTwo)
	ON_BN_CLICKED(IDC_BUTTON_THREE, &CCalculatorDlg::OnBnClickedButtonThree)
	ON_BN_CLICKED(IDC_BUTTON_FOUR, &CCalculatorDlg::OnBnClickedButtonFour)
	ON_BN_CLICKED(IDC_BUTTON_FIVE, &CCalculatorDlg::OnBnClickedButtonFive)
	ON_BN_CLICKED(IDC_BUTTON_SEX, &CCalculatorDlg::OnBnClickedButtonSex)
	ON_BN_CLICKED(IDC_BUTTON_SEVEN, &CCalculatorDlg::OnBnClickedButtonSeven)
	ON_BN_CLICKED(IDC_BUTTON_EIGHT, &CCalculatorDlg::OnBnClickedButtonEight)
	ON_BN_CLICKED(IDC_BUTTON_NINE, &CCalculatorDlg::OnBnClickedButtonNine)
	ON_BN_CLICKED(IDC_BUTTON_DOT, &CCalculatorDlg::OnBnClickedButtonDot)
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CCalculatorDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_EQUALS, &CCalculatorDlg::OnBnClickedButtonEquals)
END_MESSAGE_MAP()


// CCalculatorDlg 消息处理程序

BOOL CCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	_state = std::make_shared<NumState>();
	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCalculatorDlg::handleDigits(const char digit)
{
	auto digitsState = std::make_shared<NumState>();
	if (digitsState->changeState(_state))
	{
		_state = digitsState;
		if (_op == ' ')
		{
			if (_leftValue == '0')
				_leftValue = digit;
			else
				_leftValue += digit;

			_resultDisplay.SetWindowText(_leftValue);
		}
		else
		{
			_rightValue += digit;
			_show.SetWindowText(_leftValue + _op);
			_resultDisplay.SetWindowText(_rightValue);
		}
		
	}
	else
	{

	}
}

void CCalculatorDlg::OnBnClickedButtonZero()
{
	// TODO: 在此添加控件通知处理程序代码
	handleDigits('0');
}


void CCalculatorDlg::OnBnClickedButtonOne()
{
	// TODO: 在此添加控件通知处理程序代码
	handleDigits('1');
}


void CCalculatorDlg::OnBnClickedButtonTwo()
{
	// TODO: 在此添加控件通知处理程序代码
	handleDigits('2');
}


void CCalculatorDlg::OnBnClickedButtonThree()
{
	// TODO: 在此添加控件通知处理程序代码
	handleDigits('3');
}


void CCalculatorDlg::OnBnClickedButtonFour()
{
	// TODO: 在此添加控件通知处理程序代码
	handleDigits('4');
}


void CCalculatorDlg::OnBnClickedButtonFive()
{
	// TODO: 在此添加控件通知处理程序代码
	handleDigits('5');
}


void CCalculatorDlg::OnBnClickedButtonSex()
{
	// TODO: 在此添加控件通知处理程序代码
	handleDigits('6');
}


void CCalculatorDlg::OnBnClickedButtonSeven()
{
	// TODO: 在此添加控件通知处理程序代码
	handleDigits('7');
}


void CCalculatorDlg::OnBnClickedButtonEight()
{
	// TODO: 在此添加控件通知处理程序代码
	handleDigits('8');
}


void CCalculatorDlg::OnBnClickedButtonNine()
{
	// TODO: 在此添加控件通知处理程序代码
	handleDigits('9');
}


void CCalculatorDlg::OnBnClickedButtonDot()
{
	// TODO: 在此添加控件通知处理程序代码
	auto dotState = std::make_shared<DotState>();
	if (dotState->changeState(_state))
	{
		if (_op == ' ')
		{
			if (_leftValue.Find('.') != -1)
				return;

			_leftValue += '.';

			_resultDisplay.SetWindowText(_leftValue);
		}
		else
		{
			if (_rightValue.Find('.') != -1)
				return;

			_rightValue += '.';
			_show.SetWindowText(_leftValue + _op);
			_resultDisplay.SetWindowText(_rightValue);
		}
		_state = dotState;
	}
}


void CCalculatorDlg::OnBnClickedButtonAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	auto opState = std::make_shared<OpState>();
	if (opState->changeState(_state))
	{
		if (_rightValue.IsEmpty())
		{
			_show.SetWindowText(_leftValue + '+');
			_resultDisplay.SetWindowText(_leftValue);
			_op = '+';
		}
		else
		{
			double tmpResult;
			switch (_op)
			{
			case '+':
				tmpResult = _ttof(_leftValue) + _ttof(_rightValue);
				break;
			case '-':
				tmpResult = _ttof(_leftValue) - _ttof(_rightValue);
				break;
			case '*':
				tmpResult = _ttof(_leftValue) * _ttof(_rightValue);
				break;
			case '/':
				tmpResult = _ttof(_leftValue) / _ttof(_rightValue);
				break;
			default:
				break;
			}
			auto show = CString(std::to_string(tmpResult).c_str());
			show.TrimRight('0');
			_show.SetWindowText(show + '+');
			_resultDisplay.SetWindowText(show);
			_op = '+';
			_rightValue.Empty();
			_leftValue = show;
		}
		_state = opState;
	}
}


void CCalculatorDlg::OnBnClickedButtonEquals()
{
	// TODO: 在此添加控件通知处理程序代码
	auto qState = std::make_shared<EqualsState>();
	if (qState->changeState(_state))
	{
		if (_op != ' ')
		{
			double tmpResult;
			switch (_op)
			{
			case '+':
				tmpResult = _ttof(_leftValue) + _ttof(_rightValue);
				break;
			case '-':
				tmpResult = _ttof(_leftValue) - _ttof(_rightValue);
				break;
			case '*':
				tmpResult = _ttof(_leftValue) * _ttof(_rightValue);
				break;
			case '/':
				tmpResult = _ttof(_leftValue) / _ttof(_rightValue);
				break;
			default:
				break;
			}
			auto show = CString(std::to_string(tmpResult).c_str());
			show.TrimRight('0');
			_show.SetWindowText(_leftValue + '+' + _rightValue);
			_resultDisplay.SetWindowText(show);
			_op = ' ';
		}
	}
}
