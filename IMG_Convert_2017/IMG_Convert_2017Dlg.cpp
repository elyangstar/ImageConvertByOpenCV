
// IMG_Convert_2017Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "IMG_Convert_2017.h"
#include "IMG_Convert_2017Dlg.h"
#include "afxdialogex.h"

#include <iostream>
#include <opencv2\opencv.hpp>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CIMGConvert2017Dlg 대화 상자



CIMGConvert2017Dlg::CIMGConvert2017Dlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_IMG_CONVERT_2017_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIMGConvert2017Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CIMGConvert2017Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_IMG_MAT_LOAD, &CIMGConvert2017Dlg::OnBnClickedImgMatLoad)
	ON_BN_CLICKED(IDC_LOAD_VIDEO, &CIMGConvert2017Dlg::OnBnClickedLoadVideo)
	ON_BN_CLICKED(IDC_IMG_MAT_TEMPLATE_LOAD, &CIMGConvert2017Dlg::OnBnClickedImgMatTemplateLoad)
	ON_BN_CLICKED(IDC_LOAD_MATCHING, &CIMGConvert2017Dlg::OnBnClickedLoadMatching)
	ON_BN_CLICKED(IDC_LOAD_MATCHING_SPEEDUP, &CIMGConvert2017Dlg::OnBnClickedLoadMatchingSpeedup)
	ON_BN_CLICKED(IDC_CONTUOR_SHAPE, &CIMGConvert2017Dlg::OnBnClickedContuorShape)
	ON_BN_CLICKED(IDC_IMG_MAT_FACEDETECT, &CIMGConvert2017Dlg::OnBnClickedImgMatFacedetect)
	ON_BN_CLICKED(IDC_CHECK_FINGER_DETECT, &CIMGConvert2017Dlg::OnBnClickedCheckFingerDetect)
	ON_BN_CLICKED(IDC_CHECK_FINGER_DETECT2, &CIMGConvert2017Dlg::OnBnClickedCheckFingerDetect2)
END_MESSAGE_MAP()


// CIMGConvert2017Dlg 메시지 처리기

BOOL CIMGConvert2017Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CIMGConvert2017Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CIMGConvert2017Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CIMGConvert2017Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CIMGConvert2017Dlg::OnBnClickedImgMatLoad()
{
	CFileDialog fileDlg(TRUE, NULL, NULL, OFN_READONLY, _T("image file(*.jpg;*.bmp;*.png;)|*.jpg;*.bmp;*.png;|All Files(*.*)|*.*||"));
	BOOL bflag = FALSE;

	CString path = _T("");
	if (fileDlg.DoModal() == IDOK)
	{
		path = fileDlg.GetPathName();

		CT2CA pszString(path);
		std::string strPath(pszString);
		bflag = ((CButton*)GetDlgItem(IDC_GRAY_USE))->GetCheck();

		if (bflag == FALSE)
			m_matImage = imread(strPath, IMREAD_UNCHANGED);
		else if (bflag == TRUE)
			m_matImage = imread(strPath, IMREAD_GRAYSCALE);

		//2번 Row 참고(바로 아래)
		CreateBitmapInfo(m_matImage.cols, m_matImage.rows, m_matImage.channels() * 8);
		//Picture Control에 추가하기 위함
		DrawImage();
	}
}


void CIMGConvert2017Dlg::OnBnClickedImgMatTemplateLoad()
{
	CFileDialog fileDlg(TRUE, NULL, NULL, OFN_READONLY, _T("image file(*.jpg;*.bmp;*.png;)|*.jpg;*.bmp;*.png;|All Files(*.*)|*.*||"));
	BOOL bflag = FALSE;

	CString path = _T("");
	if (fileDlg.DoModal() == IDOK)
	{
		path = fileDlg.GetPathName();

		CT2CA pszString(path);
		std::string strPath(pszString);
		bflag = ((CButton*)GetDlgItem(IDC_GRAY_USE))->GetCheck();

		if (bflag == FALSE)
			m_matTemplateImage = imread(strPath, IMREAD_UNCHANGED);
		else if (bflag == TRUE)
			m_matTemplateImage = imread(strPath, IMREAD_GRAYSCALE);

		//2번 Row 참고(바로 아래)
		CreateBitmapInfo(m_matTemplateImage.cols, m_matTemplateImage.rows, m_matTemplateImage.channels() * 8);
		//Picture Control에 추가하기 위함
		DrawImageTemplate();
	}
}


void CIMGConvert2017Dlg::CreateBitmapInfo(int w, int h, int bpp)
{
	if (m_pBitmapInfo != NULL)
	{
		delete m_pBitmapInfo;
		m_pBitmapInfo = NULL;
	}

	if (bpp == 8)
		m_pBitmapInfo = (BITMAPINFO *) new BYTE[sizeof(BITMAPINFO) + 255 * sizeof(RGBQUAD)];
	else // 24 or 32bit
		m_pBitmapInfo = (BITMAPINFO *) new BYTE[sizeof(BITMAPINFO)];

	m_pBitmapInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	m_pBitmapInfo->bmiHeader.biPlanes = 1;
	m_pBitmapInfo->bmiHeader.biBitCount = bpp;
	m_pBitmapInfo->bmiHeader.biCompression = BI_RGB;
	m_pBitmapInfo->bmiHeader.biSizeImage = 0;
	m_pBitmapInfo->bmiHeader.biXPelsPerMeter = 0;
	m_pBitmapInfo->bmiHeader.biYPelsPerMeter = 0;
	m_pBitmapInfo->bmiHeader.biClrUsed = 0;
	m_pBitmapInfo->bmiHeader.biClrImportant = 0;

	if (bpp == 8)
	{
		for (int i = 0; i < 256; i++)
		{
			m_pBitmapInfo->bmiColors[i].rgbBlue = (BYTE)i;
			m_pBitmapInfo->bmiColors[i].rgbGreen = (BYTE)i;
			m_pBitmapInfo->bmiColors[i].rgbRed = (BYTE)i;
			m_pBitmapInfo->bmiColors[i].rgbReserved = 0;
		}
	}

	m_pBitmapInfo->bmiHeader.biWidth = w;
	m_pBitmapInfo->bmiHeader.biHeight = -h;
}

void CIMGConvert2017Dlg::DrawImage()
{
	CClientDC dc(GetDlgItem(IDC_PIC_IMG));

	CRect rect;
	GetDlgItem(IDC_PIC_IMG)->GetClientRect(&rect);

	SetStretchBltMode(dc.GetSafeHdc(), COLORONCOLOR);

	StretchDIBits(dc.GetSafeHdc(), 0, 0, rect.Width(), rect.Height(), 0, 0, m_matImage.cols, m_matImage.rows, m_matImage.data, m_pBitmapInfo, DIB_RGB_COLORS, SRCCOPY);
}

void CIMGConvert2017Dlg::DrawImageTemplate()
{
	CClientDC dc(GetDlgItem(IDC_PIC_IMG_TEMPLATE));

	CRect rect;
	GetDlgItem(IDC_PIC_IMG_TEMPLATE)->GetClientRect(&rect);

	SetStretchBltMode(dc.GetSafeHdc(), COLORONCOLOR);

	StretchDIBits(dc.GetSafeHdc(), 0, 0, rect.Width(), rect.Height(), 0, 0, m_matTemplateImage.cols, m_matTemplateImage.rows, m_matTemplateImage.data, m_pBitmapInfo, DIB_RGB_COLORS, SRCCOPY);
}
void CIMGConvert2017Dlg::OnBnClickedImgMatFacedetect()
{
	Mat frame;
	VideoCapture cap;
	CClientDC dc(GetDlgItem(IDC_PIC_IMG));
	CRect rect;

	//얼굴 인식 사진한장만 해보자.
	face_cascade.load("./Xml/haarcascade_frontalface_alt2.xml");


	cap.open(0);              // by default use webcam
	while (cap.isOpened() && cap.read(frame))
	{
		//2번 Row 참고(바로 아래)
		CreateBitmapInfo(frame.cols, frame.rows, frame.channels() * 8);
		//
		// process frame as you wish..
		if (waitKey(10) == 27) break;

		detectAndDisplay(frame);
		RealTimeMatchingPercent(frame);
		GetDlgItem(IDC_PIC_IMG)->GetClientRect(&rect);
		SetStretchBltMode(dc.GetSafeHdc(), COLORONCOLOR);
		StretchDIBits(dc.GetSafeHdc(), 0, 0, rect.Width(), rect.Height(), 0, 0, frame.cols, frame.rows, frame.data, m_pBitmapInfo, DIB_RGB_COLORS, SRCCOPY);
	}


	
}

void CIMGConvert2017Dlg::WriteSizeFile(int nwidth , int height)
{
	CString strpath = "../file/size.txt";
	FILE *file = fopen(strpath, "a");
	if (file)
	{
		//YEY - 180616 레시피에 따른 공정 라인명이 별도로 필요 하기 때문에 추가.
		fprintf(file, "%n,%n,\n", nwidth, height);    //1. file format
		fclose(file);
	}

}

void CIMGConvert2017Dlg::OnBnClickedLoadVideo()
{
	face_cascade.load("./Xml/haarcascade_frontalface_alt2.xml");

	CString strpath = _T("../file/TEST.mp4");

	CT2CA pszString(strpath);
	std::string strPath(pszString);

	VideoCapture cap(strPath);

	if (!cap.isOpened())
	{
		printf("Can't open the camera");
		return;
	}

	Mat img;

	while (1)
	{
		cap >> img;

		if (img.empty())
		{
			printf("empty image");
			return;
		}

		//cvSaveImage("D:\\img.jpg", img);
		

		detectAndDisplay(img);
		imshow("camera img", img);
		if (waitKey(25) == 27)
			break;
	}
}

void CIMGConvert2017Dlg::detectAndDisplay(Mat frame)
{
	std::vector<Rect> faces;
	Mat frame_gray;
	char mytext[30];

	cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);

	face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));

	for (size_t i = 0; i < faces.size(); i++)
	{
		if (faces[i].width < 200 && faces[i].height < 200)
			continue;

		Point center(faces[i].x + faces[i].width / 2, faces[i].y + faces[i].height / 2);
/*		rectangle(frame, faces[i],  Scalar(100 * (i - 2), 255, 255 * i), 3, 4, 0);*/

 		ellipse(frame, center, Size(faces[i].width / 2, faces[i].height / 2),
			0, 0, 360, Scalar(0, 0, 255), 4, 8, 0);

		TRACE("%d , %d \n", faces[i].width, faces[i].height);
		//WriteSizeFile(faces[i].width, faces[i].height);

		sprintf_s(mytext, "face");
		putText(frame, mytext, Point(100, 100), 1, 2, Scalar(0, 0, 255), 1);
	}

	
}

void CIMGConvert2017Dlg::FaceDetect(Mat frame)
{
	char buffer;

	CascadeClassifier face_classifier;

	//face_classifier.load("C:/opencv348/opencv/sources/data/haarcascades/haarcascade_frontalface_default.xml");

	face_classifier.load("./Xml/haarcascade_frontalface_alt2.xml");

	Mat grayframe;

	cvtColor(frame, grayframe, CV_BGR2GRAY);

	equalizeHist(grayframe, grayframe);

	vector<Rect> faces;


	face_classifier.detectMultiScale(grayframe, faces,

		1.1, // increase search scale by 10% each pass

		3,   // merge groups of three detections

		CV_HAAR_FIND_BIGGEST_OBJECT | CV_HAAR_SCALE_IMAGE,

		Size(30, 30)

	);


	Mat img_mosaic;
	Mat frame_original;
	frame.copyTo(frame_original);

	for (int i = 0; i < faces.size(); i++) {

		Point lb(faces[i].x + faces[i].width, faces[i].y + faces[i].height);

		Point tr(faces[i].x, faces[i].y);

		img_mosaic = frame(Rect(lb, tr));
		Mat img_temp;

		resize(img_mosaic, img_temp, Size(img_mosaic.rows / 8, img_mosaic.cols / 8));
		resize(img_temp, img_mosaic, Size(img_mosaic.rows, img_mosaic.cols));
		rectangle(frame, lb, tr, Scalar(100 * (i - 2), 255, 255 * i), 3, 4, 0);
		rectangle(frame_original, lb, tr, Scalar(100 * (i - 2), 255, 255 * i), 3, 4, 0);

	}

	imshow("mosaic", frame);
	imshow("webcam", frame_original);
}

//기본 연산 방법
void CIMGConvert2017Dlg::Match()
{
	Mat result;
	double minVal, maxVal;
	Point minLoc, maxLoc;
	Point matchLoc;

	//for (int i = 0; i < 6; i++)
	{
		
		//int Matching_method = i;
		/*
		0: TM_SQDIFF
		1: TM_SQDIFF NORMED
		2: TM CCORR
		3: TM CCORR NORMED
		4: TM COEFF
		5: TM COEFF NORMED";
		*/
			   
		matchTemplate(m_matImage, m_matTemplateImage, result, TM_SQDIFF);
		normalize(result, result, 0, 1, NORM_MINMAX, -1, Mat());
		minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());

		normalize(result, result, 0, 1, NORM_MINMAX, -1, Mat());
		minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());
		matchLoc = minLoc;

// 		if (Matching_method == 0 || Matching_method == 1)
// 		{
// 			matchLoc = minLoc;
// 		}
// 		else
// 			matchLoc = maxLoc;



		rectangle(m_matImage, matchLoc, Point(matchLoc.x + m_matTemplateImage.cols, matchLoc.y + m_matTemplateImage.rows), Scalar(0, 0, 255), 1);

		cvtColor(result, result, COLOR_GRAY2BGR);
		circle(result, matchLoc, 3, Scalar(0, 0, 255), 1);

		imshow("src", m_matImage);

		waitKey(0);

	}
}
// 실시간영상에서 매칭 시도하여 매칭되는곳 사각형 처리./ 나중에는 퍼센트로 안맞으면 날려야 할듯.
void CIMGConvert2017Dlg::RealTimeMatchingPercent(Mat Frame)
{
	Mat result;
	double minVal, maxVal;
	Point minLoc, maxLoc;
	Point matchLoc;

	if (m_matTemplateImage.data ==NULL)
		return;

	//for (int i = 0; i < 6; i++)
	{

		//int Matching_method = i;
		/*
		0: TM_SQDIFF
		1: TM_SQDIFF NORMED
		2: TM CCORR
		3: TM CCORR NORMED
		4: TM COEFF
		5: TM COEFF NORMED";
		*/

		matchTemplate(Frame, m_matTemplateImage, result, TM_SQDIFF_NORMED);
		normalize(result, result, 0, 1, NORM_MINMAX, -1, Mat());
		minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());

		normalize(result, result, 0, 1, NORM_MINMAX, -1, Mat());
		minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());
		matchLoc = minLoc;

		// 		if (Matching_method == 0 || Matching_method == 1)
		// 		{
		// 			matchLoc = minLoc;
		// 		}
		// 		else
		// 			matchLoc = maxLoc;



		rectangle(Frame, matchLoc, Point(matchLoc.x + m_matTemplateImage.cols, matchLoc.y + m_matTemplateImage.rows), Scalar(0, 0, 255), 1);

		cvtColor(result, result, COLOR_GRAY2BGR);
		circle(result, matchLoc, 3, Scalar(0, 0, 255), 1);

		//imshow("src", m_matImage);

		waitKey(0);

	}
}


void CIMGConvert2017Dlg::OnBnClickedLoadMatching()
{
	Match();
}


//단순히 이미지를 Resize하여 찾은 후 매칭한 방법
void CIMGConvert2017Dlg::OnBnClickedLoadMatchingSpeedup()
{
	clock_t start, end;

	double minVal, maxVal;
	Point minLoc, maxLoc;
	Point matchLoc;

	Mat result;



	resize(m_matImage, m_matImage, Size(m_matImage.cols / 2, m_matImage.rows / 2));
	resize(m_matTemplateImage, m_matTemplateImage, Size(m_matTemplateImage.cols / 2, m_matTemplateImage.rows / 2));

	//for (int i = 0; i < 6; i++)
	{
		Mat img_out;
		//m_matImage.copyTo(img_out);

		//int Matching_method = i;
		/*
		0: TM_SQDIFF
		1: TM_SQDIFF NORMED
		2: TM CCORR
		3: TM CCORR NORMED
		4: TM COEFF
		5: TM COEFF NORMED";
		*/

		start = clock();


		matchTemplate(m_matImage, m_matTemplateImage, result, 0);
		normalize(result, result, 0, 1, NORM_MINMAX, -1, Mat());
		minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());
		//minMaxLoc(result, &minVal, NULL, &minLoc, NULL);
		matchLoc = minLoc;
	

		end = clock();

		//cout << "Searching time : " << difftime(end, start) / CLOCKS_PER_SEC << endl;

		double searching_time = difftime(end, start) / CLOCKS_PER_SEC;
		char mytext[30];
		sprintf_s(mytext, "searching time : %lf", searching_time);

		putText(m_matImage, mytext, Point(100, 100), 1, 2, Scalar(0, 0, 255), 1);

		rectangle(m_matImage, matchLoc, Point(matchLoc.x + m_matTemplateImage.cols, matchLoc.y + m_matTemplateImage.rows), Scalar(0, 0, 255), 1);

		cvtColor(result, result, COLOR_GRAY2BGR);
		circle(result, matchLoc, 3, Scalar(0, 0, 255), 1);

		imshow("src", m_matImage);
		//imshow("templ", templ);
		//imshow("result", result);

		waitKey(0);

	}
	return ;
}

void CIMGConvert2017Dlg::setLabel(Mat& image, string str, vector<Point> contour)
{
	int fontface = FONT_HERSHEY_SIMPLEX;
	double scale = 0.5;
	int thickness = 1;
	int baseline = 0;

	Size text = getTextSize(str, fontface, scale, thickness, &baseline);
	Rect r = boundingRect(contour);

	Point pt(r.x + ((r.width - text.width) / 2), r.y + ((r.height + text.height) / 2));
	rectangle(image, pt + Point(0, baseline), pt + Point(text.width, -text.height), CV_RGB(200, 200, 200), FILLED);
	putText(image, str, pt, fontface, scale, CV_RGB(0, 0, 0), thickness, 8);
}




void CIMGConvert2017Dlg::OnBnClickedContuorShape()
{
	Mat img_result, img_gray;

	//이미지파일을 로드하여 image에 저장  
	
	if (m_matImage.empty())
	{
		cout << "Could not open or find the image" << std::endl;
		return;
	}


	//그레이스케일 이미지로 변환  
	cvtColor(m_matImage, img_gray, COLOR_BGR2GRAY);

	//이진화 이미지로 변환
	Mat binary_image;
	threshold(img_gray, img_gray, 0, 255, THRESH_BINARY_INV | THRESH_OTSU);

	//contour를 찾는다.
	vector<vector<Point> > contours;
	findContours(img_gray, contours, RETR_LIST, CHAIN_APPROX_SIMPLE);

	//contour를 근사화한다.
	vector<Point2f> approx;
	img_result = m_matImage.clone();

	for (size_t i = 0; i < contours.size(); i++)
	{
		approxPolyDP(Mat(contours[i]), approx, arcLength(Mat(contours[i]), true)*0.02, true);

		if (fabs(contourArea(Mat(approx))) > 100)  //면적이 일정크기 이상이어야 한다. 
		{

			int size = approx.size();

			//Contour를 근사화한 직선을 그린다.
			if (size % 2 == 0) {
				line(img_result, approx[0], approx[approx.size() - 1], Scalar(0, 255, 0), 3);

				for (int k = 0; k < size - 1; k++)
					line(img_result, approx[k], approx[k + 1], Scalar(0, 255, 0), 3);

				for (int k = 0; k < size; k++)
					circle(img_result, approx[k], 3, Scalar(0, 0, 255));
			}
			else {
				line(img_result, approx[0], approx[approx.size() - 1], Scalar(0, 255, 0), 3);

				for (int k = 0; k < size - 1; k++)
					line(img_result, approx[k], approx[k + 1], Scalar(0, 255, 0), 3);

				for (int k = 0; k < size; k++)
					circle(img_result, approx[k], 3, Scalar(0, 0, 255));
			}



			//도형을 판정한다.
			if (size == 3)
				setLabel(img_result, "triangle", contours[i]); //삼각형

			//이하는 해당 꼭지점을 가진 convex라면 찾는 도형
			else if (size == 4 && isContourConvex(Mat(approx))) 
				setLabel(img_result, "rectangle", contours[i]); //사각형

			else if (size == 5 && isContourConvex(Mat(approx))) 
				setLabel(img_result, "pentagon", contours[i]); //오각형

			else if (size == 6 && isContourConvex(Mat(approx))) 
				setLabel(img_result, "hexagon", contours[i]);  //육각형

			else if (size == 10 && isContourConvex(Mat(approx))) 
				setLabel(img_result, "decagon", contours[i]);    //십각형

			//위 조건에 해당 안되는 경우는 찾아낸 꼭지점 갯수를 표시
			else setLabel(img_result, to_string(approx.size()), contours[i]);
		}

	}


	imshow("input", m_matImage);
	imshow("result", img_result);


	waitKey(0);


	return;
}



cv::Point getHandCenter(cv::Mat &mask, double &radius);
float fingerEnd(float p1, float p2, float t1, float t2, float q1, float q2);

int drawX, drawY;

void CIMGConvert2017Dlg::OnBnClickedCheckFingerDetect()
{

	std::vector<cv::Point> saveLine;

	int erosion_value = 0;
	int const max_erosion = 2;
	int erosion_size = 0;
	int const ersion_max_size = 21;
	int dilation_value = 0;
	int dilation_size = 0;
	int erosion_type = 0;


	cv::Mat element;
	cv::Mat frame, tmpImg;
	cv::Mat handImg, mask, mask1;
	cv::Point dst;

	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;
	
	double radius = 5;
	cv::VideoCapture video(0);

	if (!video.isOpened()) return;

	cv::namedWindow("change_image", CV_WINDOW_AUTOSIZE);
	cv::namedWindow("original_image", CV_WINDOW_AUTOSIZE);
	cv::createTrackbar("ele_erosion", "original_image", &erosion_value, max_erosion);
	cv::createTrackbar("erosion_size", "original_image", &erosion_size, ersion_max_size);
	cv::createTrackbar("ele_dilation", "original_image", &dilation_value, max_erosion);
	cv::createTrackbar("dilation_size", "original_image", &dilation_size, ersion_max_size);

	while (true)
	{
		video >> tmpImg;

		if (tmpImg.empty()) break;

		if (erosion_value == 0) erosion_type = cv::MORPH_RECT;
		else if (erosion_value == 1) erosion_type = cv::MORPH_CROSS;
		else if (erosion_value == 2) erosion_type = cv::MORPH_ELLIPSE;

		element = cv::getStructuringElement(erosion_type, cv::Size(2 * erosion_size + 1, 2 * erosion_size + 1), cv::Point(erosion_size, erosion_size));

		//손 색깔을 검출하기 위해서 YCbCr 컬러 모델 사용. 잡음에 강하다고..
		//Y는 휘도 성분, Cb, Cr은 색차 성분
		//피부색이 가지는 Cb,Cr의 영역은 
		//Cb: 77 ~ 127
		//Cr: 133 ~ 173

		cv::cvtColor(tmpImg, handImg, CV_BGR2YCrCb);
		cv::inRange(handImg, cv::Scalar(0, 133, 77), cv::Scalar(255, 173, 127), handImg);

		cv::erode(handImg, handImg, element);
		cv::dilate(handImg, handImg, element);

		mask = handImg.clone();


		cv::findContours(mask, contours, hierarchy, CV_RETR_LIST, CV_CLOCKWISE, cv::Point(0,0));
		
		

		int largestContour = 0;
		
		for (int i = 0; i < contours.size(); i++) {
			if (cv::contourArea(contours[i]) > cv::contourArea(contours[largestContour])) {
				largestContour = i;
			}
		}

		cv::drawContours(tmpImg, contours, largestContour, cv::Scalar(0, 255, 255), 1, 8, std::vector < cv::Vec4i>(), 0, cv::Point());	//contour 그리기

		if (!contours.empty()) {
			std::vector<std::vector<cv::Point>>hull(1);

			cv::convexHull(cv::Mat(contours[largestContour]), hull[0], false);
			cv::drawContours(tmpImg, hull, 0, cv::Scalar(0, 255, 0), 1, 8, std::vector<cv::Vec4i>(), 0, cv::Point());		//점 잇기

			if (hull[0].size() > 2) {
				
				cv::Rect boundingBox = cv::boundingRect(hull[0]);
				cv::Point center = cv::Point(boundingBox.x + boundingBox.width / 2, boundingBox.y + boundingBox.height / 2);
				
				std::vector<cv::Point> validPoints;

				std::vector<int> hullIndex;
				
				cv::convexHull(cv::Mat(contours[largestContour]), hullIndex);
				std::vector<cv::Vec4i> convexityDefects;
				
				cv::convexityDefects(cv::Mat(contours[largestContour]), hullIndex, convexityDefects);

				for (int i = 0; i < convexityDefects.size(); i++) {
					cv::Point p1 = contours[largestContour][convexityDefects[i][0]];
					cv::Point p2 = contours[largestContour][convexityDefects[i][1]];
					cv::Point p3 = contours[largestContour][convexityDefects[i][2]];
					//cv::line(tmpImg, p1, p3, cv::Scalar(255, 0, 0), 2);
					//cv::line(tmpImg, p3, p2, cv::Scalar(255, 0, 0), 2);

					double angle = std::atan2(center.y - p1.y, center.x - p1.x) * 180 / CV_PI;
					double inA = fingerEnd(p1.x, p1.y, p2.x, p2.y, p3.x, p3.y);
					double length = std::sqrt(std::pow(p1.x - p3.x, 2) + std::pow(p1.y - p3.y, 2));
				
					if (angle > -30 && angle < 160 && std::abs(inA) > 20 && std::abs(inA) < 120 && length > 0.1 * boundingBox.height)
					{
						validPoints.push_back(p1);
					}
				}

				int maxY = 0, maxX=0;
				
				if (validPoints.size() != 0) {
					maxY = validPoints[0].y, maxX = validPoints[0].x;

					for (int i = 0; i < validPoints.size(); i++)
					{
						if (validPoints[i].y < maxY) {
							maxY = validPoints[i].y;
							maxX = validPoints[i].x;
						}
						cv::circle(tmpImg, cv::Point(maxX, maxY), 9, cv::Scalar(255, 0, 0), 2);
						
						saveLine.push_back(cv::Point(maxX, maxY));						

						for (std::vector<int>::size_type i = 0; i < saveLine.size(); i++) {
							cv::line(tmpImg, saveLine[i], saveLine[i], cv::Scalar(255, 5, 222), 5);
						}

						if (cv::waitKey(10) == 32) {
							saveLine.clear();
						}
						maxY = 0; maxX = 0;
					}
				}
			}
		}
		
		cv::line(tmpImg, cv::Point(drawX, drawY), cv::Point(drawX, drawY), cv::Scalar(0, 0, 0), 3, 8, 0);

		cv::flip(handImg, handImg, 1);	//영상 반전
		cv::flip(tmpImg, tmpImg, 1);	//영상 반전
		
		cv::imshow("change_image", handImg);
		cv::imshow("original_image", tmpImg);

		if (cv::waitKey(10) == 27) {
			break;
		}
	}


	video.release();
	tmpImg.release();
	frame.release();

	cv::destroyAllWindows();

	return;
}

cv::Point getHandCenter(cv::Mat &mask, double &radius)
{
	int maxDst[2];

	cv::Mat dst;	//행렬 저장
	cv::distanceTransform(mask, dst, CV_DIST_L2, 5);

	//최솟값 필요 없음
	cv::minMaxIdx(dst, NULL, &radius, NULL, maxDst, mask);

	return cv::Point(maxDst[1], maxDst[0]);
}

float fingerEnd(float p1, float p2, float t1, float t2, float q1, float q2)
{
	//두점 사이 거리 계산하기 위해. 제곱근 계산하는 sqrt
	float dist1 = std::sqrt((p1 - q1)*(p1 - q1) + (p2 - q2)*(p2 - q2));
	float dist2 = std::sqrt((t1 - q1)*(t1 - q1) + (t2 - q2)*(t2 - q2));

	float aX, aY;
	float bX, bY;
	float cX, cY;

	cX = q1;
	cY = q2;

	if (dist1 < dist2) {
		bX = p1;
		bY = p2;
		aX = t1;
		aY = t2;
	}
	else {
		bX = t1;
		bY = t2;
		aX = p1;
		aY = p2;
	}

	float r1 = cX - aX;
	float r2 = cY - aY;
	float z1 = bX - aX;
	float z2 = bY - aY;

	float result = std::acos((z1*r1 + z1 * r2) / (std::sqrt(z1*z1 + z2 * z2) * std::sqrt(r1*r1 + r2 * r2)));

	result = result * 180 / CV_PI;

	return result;
}



/*
손 인식을 하기 위해 YCrCb라는 색공간을 이용한다.

Cr:133~173
Cb:77~127

이 일반적인 살색 이라고 한다.
import cv2
import numpy as np

img = cv2.imread('./hand_sample.jpg')

#YCrCb 변환
ycrcb = cv2.cvtColor(img, cv2.COLOR_BGR2YCrCb)
#Cr:133~173, Cb : 77~127
mask_hand = cv2.inRange(ycrcb, np.array([0, 133, 77]), np.array([255, 173, 127]))

cv2.imshow("Hands", mask_hand)
cv2.imshow("Origin", img)

cap.release()
cv2.destroyAllWindows()
*/

void CIMGConvert2017Dlg::OnBnClickedCheckFingerDetect2()
{
	VideoCapture cam;
	cam.open(0);

	if (!cam.isOpened()) 
	{
		cout << "Camera open error" << endl;
		abort();
	}

	CascadeClassifier cascade;
	if (!cascade.load("./Xml/haarcascade_hand.xml")) {
		cout << "xml file load error" << endl;
		abort();
	}

	Mat frame;
	while (true) {
		cam >> frame;
		if (frame.empty()) {
			cout << "frame capture error" << endl;
			abort();
		}

		detectHand(frame, cascade);
		imshow("Frame", frame);
		waitKey(1);
	}
}


void CIMGConvert2017Dlg::detectHand(Mat& frame, CascadeClassifier& cascade)
{
	vector<Rect> hands;
	Mat frameGray, edge;

	cvtColor(frame, frameGray, CV_BGR2GRAY);

	//threshold(frameGray, frameGray, 100, 255, CV_THRESH_BINARY);
	//GaussianBlur(frameGray, frameGray, Size(11,11), 0, 0); 
	//Canny(frameGray, edge, (float)1.0, (float)3.0, 5);


//cascade.detectMultiScale(frame, hands, 1.2, 2, CV_HAAR_DO_CANNY_PRUNING, Size(100,100));

	equalizeHist(frameGray, frameGray);
	cascade.detectMultiScale(frameGray, hands, 1.1, 3, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));
	for (int i = 0; i < hands.size(); i++)
		rectangle(frame, hands[i], Scalar(255, 0, 0), 2);
}
