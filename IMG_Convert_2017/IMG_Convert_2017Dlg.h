
// IMG_Convert_2017Dlg.h: 헤더 파일
//

#pragma once
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

#define FACEDETECT_DLL_TYPE __declspec(dllexport);

// CIMGConvert2017Dlg 대화 상자
class CIMGConvert2017Dlg : public CDialog
{
// 생성입니다.
public:
	CIMGConvert2017Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_IMG_CONVERT_2017_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBnClickedLoadVideo();
	afx_msg void OnBnClickedImgMatTemplateLoad();
	afx_msg void OnBnClickedLoadMatching();
	afx_msg void OnBnClickedLoadMatchingSpeedup();
	afx_msg void OnBnClickedContuorShape();
	DECLARE_MESSAGE_MAP()

	
public:
	afx_msg void OnBnClickedImgMatLoad();
	
	Mat m_matImage;
	Mat m_matTemplateImage;
	BITMAPINFO *m_pBitmapInfo; // Bitmap 정보를 담고 있는 구조체.
	void	CreateBitmapInfo(int w, int h, int bpp);

	//Picture Ctrl 그리기
	void	DrawImage();
	void	DrawImageTemplate();

	//기능 관련
	void detectAndDisplay(Mat frame);			//찾아서 출력하기
	void Match();								//영역 매칭
	void RealTimeMatchingPercent(Mat Frame);
	void FaceDetect(Mat frame);					//얼굴 찾기
	void setLabel(Mat& image, string str, vector<Point> contour);		//이미지에 글자 쓰기
	
	cv::CascadeClassifier face_cascade;


	afx_msg void OnBnClickedImgMatFacedetect();

	void WriteSizeFile(int nwidth, int height);
};
