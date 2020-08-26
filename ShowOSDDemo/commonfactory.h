#define CHNS TEXT("Chs")
#define TCH TEXT("Tch")
#define JAP TEXT("Jpn")
#define KOREA TEXT("Kor")
#define ENG TEXT("Eng")
#define ESP TEXT("Esp")
#define FIN TEXT("Fin")
#define TUR TEXT("Tur")
#define SWE TEXT("Swe")
#define PTG TEXT("Ptg")
#define BRZ TEXT("Brz")
#define POL TEXT("Pol")
#define HUN TEXT("Hun")
#define DAN TEXT("Dan")
#define DUT TEXT("Dut")
#define FRA TEXT("Fra")
#define ITA TEXT("Ita")
#define CZE TEXT("Cze") 
#define DEU TEXT("Deu")
#define VIE TEXT("Vie")
#define SLO TEXT("Slo")
#define BUL TEXT("Bul")
#define RUS TEXT("Rus")
#define CRO TEXT("Cro")
#define GRK TEXT("Grk")
#define HEB TEXT("Heb")
#define IND TEXT("Ind")
#define ROM TEXT("Rom")
#define SLK TEXT("Slk")
#define THA TEXT("Tha")
#define ARA TEXT("Ara")
#define NOR TEXT("Nor")
struct ProcessTemplate{
	UINT WordSize;			//First using CString wrap chars,then using sizeof send it in
	float WidthScope;			//the maximal width should not over this scope
	float RetunWidth;
	float Split;
} static pTemplate={0,0,0,0};

class CommonFactory{
public:
	static void OperateIamgePos(ProcessTemplate *templateA){
		templateA->Split=getCurrentString();
		float returnValue=(templateA->Split)*((float)(templateA->WordSize));
		if(returnValue<=(templateA->WidthScope)){
			templateA->RetunWidth=returnValue;
			return;
		}else if(returnValue>(templateA->WidthScope)){
			templateA->RetunWidth=templateA->WidthScope;
			return;
		}
	}//end method
	static CString getLoacle(){
		CString rtnValue;
		HINSTANCE	hInstance =AfxGetInstanceHandle();
		TCHAR		szString[MAX_PATH];
		LoadString(hInstance, IDS_HELPFILE, szString, MAX_PATH);
		rtnValue.Append(szString);
		::ZeroMemory(&szString,sizeof(szString));
		int dotPos=rtnValue.Find(TEXT("."));
		rtnValue.Truncate(rtnValue.GetLength()-(dotPos+1));
		return rtnValue;
	}
	static float getBatteryString(){
		CString rtnValue=CommonFactory::getLoacle();
		if(rtnValue==SLO||rtnValue==BUL||rtnValue==CRO||rtnValue==HUN||rtnValue==SLK||rtnValue==THA){
			return 6.0f;		//to split
		}else if(rtnValue==CHNS||rtnValue==TCH){
			return 30.0f;		//to split
		}else if(rtnValue==CZE||rtnValue==VIE){
			return 5.8f;
		}else if(rtnValue==DEU||rtnValue==FRA||rtnValue==ITA){
			return 6.5f;
		}else if(rtnValue==JAP){
			return 17.0f;
		}else if(rtnValue==KOREA){
			return 12.0f;
		}else if(rtnValue==POL){
			return 5.6f;
		}else if(rtnValue==BRZ||rtnValue==TUR||rtnValue==SWE){
			return 7.0f;
		}
		return 8.0f;
	}
	static float getDoubleString(){
		CString rtnValue=CommonFactory::getLoacle();
		if(rtnValue==POL||rtnValue==SLK||rtnValue==CZE){
			return 6.2f;		//to split
		}else if(rtnValue==CHNS||rtnValue==TCH){
			return 30.0f;		//to split
		}else if(rtnValue==DEU||rtnValue==FRA||rtnValue==ITA||rtnValue==VIE||rtnValue==SLO||rtnValue==CRO||rtnValue==HUN){
			return 6.5f;
		}else if(rtnValue==BUL||rtnValue==THA){
			return 6.8f;
		}else if(rtnValue==JAP){
			return 17.0f;
		}else if(rtnValue==KOREA){
			return 12.0f;
		}else if(rtnValue==BRZ||rtnValue==TUR||rtnValue==SWE||rtnValue==ARA){
			return 7.0f;
		}
		return 8.0f;
	}
	static float getBatteryOnlyString(){
		CString rtnValue=CommonFactory::getLoacle();
		if(rtnValue==CHNS||rtnValue==TCH){
			return 30.0f;		//to split
		}else if(rtnValue==JAP||rtnValue==KOREA){
			return 17.0f;
		}else if(rtnValue==CZE||rtnValue==FIN||rtnValue==DEU||rtnValue==TUR){
			return 12.0f;
		}else if(rtnValue==BRZ||rtnValue==DAN||rtnValue==PTG||rtnValue==ROM
			||rtnValue==FRA||rtnValue==ITA||rtnValue==SLO||rtnValue==CRO||rtnValue==HUN
			||rtnValue==BUL||rtnValue==THA||rtnValue==NOR||rtnValue==ESP){
			return 7.8f;
		}else if(rtnValue==DUT||rtnValue==IND||rtnValue==SWE){
			return 8.0f;
		}
		return 9.0f;
	}
	static float getSmartOnlyString(){
		CString rtnValue=CommonFactory::getLoacle();
		if(rtnValue==CHNS||rtnValue==TCH){
			return 30.0f;		//to split
		}else if(rtnValue==KOREA){
			return 14.0f;
		}else if(rtnValue==JAP){
			return 17.0f;
		}else if(rtnValue==DUT||rtnValue==IND||rtnValue==SWE||rtnValue==ENG||rtnValue==RUS||rtnValue==PTG||rtnValue==BRZ||rtnValue==NOR||rtnValue==HEB
			||rtnValue==GRK||rtnValue==DAN||rtnValue==ARA){
			return 7.8f;
		}else if(rtnValue==ROM){
			return 9.0f;
		}else if(rtnValue==POL||rtnValue==HUN||rtnValue==FRA){
			return 6.4f;
		}else if(rtnValue==DEU||rtnValue==BUL){
			return 7.1f;
		}
		return 6.8f;
	}
	static float getIntellOnlyString(){
		CString rtnValue=CommonFactory::getLoacle();
		if(rtnValue==CHNS||rtnValue==TCH){
			return 30.0f;		//to split
		}else if(rtnValue==JAP||rtnValue==KOREA){
			return 16.0f;
		}else if(rtnValue==HUN||rtnValue==FRA||rtnValue==CZE||rtnValue==SLK){
			return 6.4f;
		}else if(rtnValue==DEU||rtnValue==NOR||rtnValue==POL||rtnValue==BRZ||rtnValue==PTG||rtnValue==THA||rtnValue==TUR||rtnValue==VIE){
			return 7.1f;
		}else if(rtnValue==DAN||rtnValue==ITA||rtnValue==ROM||rtnValue==ESP){
			return 6.8f;
		}else if(rtnValue==GRK){
			return 8.4f;
		}else if(rtnValue==RUS){
			return 9.0f;
		}
		return 7.8f;
	}
private:
	static float getCurrentString(){
		CString rtnValue=CommonFactory::getLoacle();
		if(rtnValue==HUN){
			pTemplate.WidthScope=150;
		}
		if(rtnValue==JAP||rtnValue==KOREA){
			return 14.0f;
		}else if(rtnValue==CHNS||rtnValue==TCH){
			return 15.5f;		//to split
		}else if(rtnValue==ARA||rtnValue==ENG||rtnValue==ESP||rtnValue==FIN||rtnValue==PTG||rtnValue==BRZ||rtnValue==POL
				||rtnValue==HUN||rtnValue==IND||rtnValue==DAN||rtnValue==DUT||rtnValue==FRA||rtnValue==CZE||rtnValue==VIE||rtnValue==SLO
				||rtnValue==BUL||rtnValue==CRO||rtnValue==HEB||rtnValue==SLK){
			return 7.0f;		//to split
		}else if (rtnValue==ITA||rtnValue==DEU||rtnValue==TUR||rtnValue==ROM||rtnValue==SWE){
			return 5.9f;
		}else{
			return 9.3f;
		}
	}

};