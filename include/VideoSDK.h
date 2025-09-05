#ifndef HIK_VIDEOSDK_H
#define HIK_VIDEOSDK_H

#if (defined(WIN32) || defined(WIN64))
#if defined(VIDEOSDK_EXPORTS)
#define VIDEOSDK_DECLARE extern "C" __declspec(dllexport)
#else
#define VIDEOSDK_DECLARE extern "C" __declspec(dllimport)
#endif // defined(VIDEOSDK_EXPORTS)

#ifndef CALLBACK
#define CALLBACK __stdcall
#endif

#else
#define VIDEOSDK_DECLARE extern "C"
#ifndef CALLBACK
#define CALLBACK
#endif
#endif  // (defined(WIN32) || defined(WIN64))

#ifndef _IN_
#define _IN_            // ��ʾ���
#endif

#ifndef _OUT_
#define _OUT_           // ��ʾ����
#endif

typedef long long VIDEO_INT64;  // ͳһ8�ֽ���������

                                ////////////////////////// �����붨�� ////////////////////////////////
#define VIDEO_ERR_FAIL            -1     // ʧ��
#define VIDEO_ERR_SUCCESS          0     // �ɹ�
#define VIDEO_ERR_PARAM            1     // ��������
#define VIDEO_ERR_INVALID_POINTER  2     // ��ָ��
#define VIDEO_ERR_NOT_INIT         3     // δ��ʼ��
#define VIDEO_ERR_INVALID_HANDLE   4     // �����Ч
#define VIDEO_ERR_CREATE_INSTANCE  5     // ����ʵ��ʧ��
#define VIDEO_ERR_APPLY_MEMORY     6     // �����ڴ�ʧ��
#define VIDEO_ERR_NET_EXCEPTION    7     // �����쳣
#define VIDEO_ERR_NOT_SUPPORT      8     // ��֧�֣���ֻȡ��ʱץͼ��rtp����ѯ��ǰ����ʱ���
#define VIDEO_ERR_SET_CALLBACK     9     // �ص�����ʧ��
#define VIDEO_ERR_START_STREAM     10    // ȡ��ʧ��
#define VIDEO_ERR_STOP_STREAM      11    // ֹͣȡ���쳣
#define VIDEO_ERR_START_PLAY       12    // ����ʧ��
#define VIDEO_ERR_STOP_PLAY        13    // ֹͣ�����쳣
#define VIDEO_ERR_TIMESTAMP        14    // ʱ�����Ч
#define VIDEO_ERR_SOUND            15    // ������ش���
#define VIDEO_ERR_SNAP             16    // ץ��ʧ��
#define VIDEO_ERR_GETPLAYTIME      17    // ��ѯ����ʱ���ʧ��
#define VIDEO_ERR_INNER            18    // �ڲ�����
#define VIDEO_ERR_PLAYCTRL         19    // ���š����ؿ���ʧ��
#define VIDEO_ERR_OPER_ORDER       20    // �������򲻶ԣ���δ�������ͻ�ȡ����������������
#define VIDEO_ERR_DISKSPACE        21    // ���̿ռ䲻��
#define VIDEO_ERR_LOADLIBARAY      22    // ģ�����ʧ�ܣ�һ��ָөʯ������ص�dll����ȱ���ԭ���޷�����
#define VIDEO_ERR_VIDEOINFO        23    // ��ѯ��Ƶ����ʧ��
#define VIDEO_ERR_CREATEFILE       24    // ������Ŀ¼���ʧ�ܣ�һ����·�����ļ����ƺ��зǷ��ַ�����·����Ŀ¼����ȫ�ǿո��ַ�������Ӣ���µġ�*������|���Լ�Ӣ���µġ�?��
#define VIDEO_ERR_OSD              25    // �����ַ����Ӵ���
#define VIDEO_ERR_TALK             26    // �Խ���ش���
#define VIDEO_ERR_DEVICE           27    // �豸��ش�����Խ��޷���⵽�����豸�������ɼ��豸
#define VIDEO_ERR_ALLOC_RESOURCE   28    // ������Դ����
#define VIDEO_ERR_PRIVATEDATA_CTRL 29    // ˽�����ݿ���ʧ��
#define VIDEO_ERR_MAX_ABILITY      30    // �����������������¼�����ػ�¼����Ҫת��װʱ�ﵽת��װ·������
#define VIDEO_ERR_STREAM_TRANSFORM 31    // ������ת������
#define VIDEO_ERR_FILE_INIVALID    32    // ��Ч�ļ����ϵ�����ʱ�������ļ����ֲ����϶ϵ�����Ҫ��ʱ�ᱨ�˴����룬һ�㱨�˴������ʾ�ļ������ݲ��㣬�����Է����ϵ�������Ϣ��
#define VIDEO_ERR_TIMESTAMP_NOT_IN_RANGE 33  // ¼������ʱָ���ϵ����������������ϵ㴦ʱ�䲻��ָ���Ŀ�ʼ�����ʱ��֮��
#define VIDEO_ERR_INSTANSPLAY      34    // ��ʱ�ط���ش���
#define VIDEO_ERR_EAGLEEYE         35    // ӥ����ش���
#define VIDEO_ERR_CONFIG           36    // �����ļ����������


#define VIDEO_ERR_DIGITALZOOM      100   // ���ӷŴ���ش���
#define VIDEO_ERR_EZVIZ_NOT_INIT   300   // өʯδ��ʼ��
#define VIDEO_ERR_FILE_NOT_EXIST   500   // �ļ������ڣ�һ��ָөʯ������ص�dll��exe
#define VIDEO_ERR_TIMEOUT          501   // ����ʱ��һ��ֱָ��өʯ����ͨ�ŵĳ�ʱ
#define VIDEO_ERR_PROCESS_STARTUP  502   // өʯ��������ʧ��
#define VIDEO_ERR_EZVIZ_RELATIVE_PATH  502   //�����ļ���өʯ�������VIdeoSDK.dll·�����ô���
#define VIDEO_ERR_PROCESSFRAMEWORK 600   // ���̿����ش���
#define VIDEO_ERR_EZVIZ            700   // өʯҵ�����ش���
#define VIDEO_ERR_OTHER            10000 // ��������


////////////////////////// �ص����� ///////////////////////////////
// �����ص�
// i64PlayHandle��Ԥ����طŽӿڷ��صľ��
// iStreamDataType�������������ͣ�0-����ͷ 1-�������� 2-�������
// pDataArray�����������飨�赱�ɶ�����������������
// iDataLen�������ݳ���
// pUserData���û�����
typedef void(CALLBACK * pfnStreamCallback)(VIDEO_INT64 i64PlayHandle, int iStreamDataType, const char* pDataArray, int iDataLen, void* pUserData);

// ȡ����������Ϣ��өʯ�����Խ���Ϣ�ص�
// i64PlayHandle��Ԥ����طŽӿڷ��صľ�������ص����������Խ�ȡ����Ϣʱ����ֵ��Чֵ��-1��
// iMsg����Ϣ���ͣ�1-���ſ�ʼ 2-���Ž�������ƵԤ���޴���Ϣ�� 3-�����쳣 4-���ż�����Կ���� 10-ȡ����ʼ 11-ȡ������ 12-ȡ���쳣 13-����ȡ����֧�� 30-��ʱ�طſ�ʼ���� 31-��ʱ�طŽ���������������Ž���ʱ���У�ֹͣ��ʱ�طŲ���ص�����Ϣ�� 50-�첽ʱ����ȡ������ɹ� 51-�첽ʱ����ȡ������ʧ�� 70-өʯ��ʼ�����Խ��ɹ���Ϣ 71-өʯֹͣ�����Խ��ɹ���Ϣ72-өʯ�����Խ��쳣��Ϣ
typedef void(CALLBACK * pfnMsgCallback)(VIDEO_INT64 i64PlayHandle, int iMsg, void* pUserData);

// ��ͼ�ص�
// i64PlayHandle��Ԥ����طŽӿڷ��صľ��
// hDC��HDC
// pUserData���û�����
// iDrawType����ͼ���ͣ�0-��ͨ��ͼ�ص� 1-���ӷŴ�ʱȫ�����ڻ�ͼ�ص�
typedef void (CALLBACK* DrawCallback)(VIDEO_INT64 i64PlayHandle, void* hDC, void* pUserData, int iDrawType);

// YUV���ݻص�
// i64PlayHandle��Ԥ����طŽӿڷ��صľ��
// pDataArray��YUV�������飨�赱�ɶ�����������������
// iDataLen�������ݳ���
// iWidth��ͼ����
// iHeight��ͼ��߶�
// iFrameType��ͼ��YUV���ͣ�ĿǰΪYV12��ֵΪ3��
// iTimeStamp��ʱ���
// pUserData���û�����
typedef void(CALLBACK* pfnDecodedDataCallback)(VIDEO_INT64 i64PlayHandle, const char* pDataArray, int iDataLen, int iWidth, int iHeight, int iFrameType, int iTimeStamp, void* pUserData);

// ¼�����ػص����������Ϣ��
// i64DownloadHandle������¼�����ؾ��
// fPercent��������¼����ȣ���iMsgΪ0ʱ������Ч
// iMsg��¼��������Ϣ��0-��ʼ¼������ 1-¼�������� 2-¼��������� 3-¼�����ؼ����ְ� 4-¼�����طְ�ʧ�� 5-¼�����طְ���� 6-¼������ʱ���� 30-ת��װ��֧�� 50-�ϵ�������֧�� 100-����ʧ�ܣ��ڲ�����
// pUserData���û��Զ�������
typedef void (CALLBACK* pfnDownloadCallback)(VIDEO_INT64 i64DownloadHandle, float fPercent, int iMsg, void* pUserData);

// ֱ��өʯ¼��طŲ�ѯ����ص�
// i64PlayHandle���طŽӿڷ��صľ��
// iErrorCode����ѯ¼������룬��ѯʧ��ʱ�����صĴ�������Ϣ
// pszRecordSegments��¼��Ƭ���ַ���
typedef long long (CALLBACK* pfnRecordSegmentCallback)(VIDEO_INT64 i64PlayHandle, int iErrorCode, const char* pszJsonRecordSegments, int iDataLen, void* pUserData);

// ֱ��өʯ����token�ص�
// pUserData: �û��Զ�������
typedef long long (CALLBACK* pfnUpdataEzvizTokenCallback)(void* pUserData);

////////////////////////// �ṹ�嶨�� //////////////////////////////////
typedef struct stPlayReq
{
    int iHardWareDecode;                // �Ƿ���GPUӲ�� 0-������ 1-�������������Ӳ�⣬�����Կ���֧�ֵȵ��´���SDK�ڲ��Զ��л�����⣻����Ӳ��ֻ��������ʾ���ܣ������ܼ����ڴ�ռ���ʣ���������ر����󣬽��鲻����Ӳ�⣩
    const char* strUsrmsg;              //hps�Ự����������ˮӡ
	const char* appkey;					//��������ak,sk
	const char* secretkey;			
    pfnStreamCallback fnStream;         // �������ݻص�
    pfnMsgCallback fnMsg;               // ���š�ȡ����Ϣ�ص�
    pfnDecodedDataCallback fnDecodedStream;     // ������YUV���ݻص���ע�⿪����GPUӲ�ⲻ֧�ֻص���������ݣ���ʱָ���˻ص�Ҳ����Ч
    void* pUserData;                    // �û�����
    char szReserve[64];                 // ��䡰smallEagleEye����ʶСӥ���豸����״ӥ���豸���������Ϊ��ͨ�豸���������ֵ-δ���壨����Ҫ��䣬����������smallEagleEye�����ֵ��
}VIDEO_PLAY_REQ, *PVIDEO_PLAY_REQ;

typedef struct stFilePlayReq
{
    pfnMsgCallback fnMsg;               // ���š�ȡ����Ϣ�ص�
    void* pUserData;                    // �û�����
    char szReserve[64];                 // ��������
}VIDEO_FILEPLAY_REQ, *PVIDEO_FILEPLAY_REQ;

typedef struct stEzvizRealPlayReq
{
    int iStreamType;                    // �����������ͣ�1-������ 0-������
    int iChannelNo;                     // өʯ�豸ͨ����
	int iHardWareDecode;                // �Ƿ���GPUӲ�� 0-������ 1-�������������Ӳ�⣬�����Կ���֧�ֵȵ��´���SDK�ڲ��Զ��л�����⣻����Ӳ��ֻ��������ʾ���ܣ������ܼ����ڴ�ռ���ʣ���������ر����󣬽��鲻����Ӳ�⣩
    pfnStreamCallback fnStream;         // �������ݻص�
    pfnMsgCallback fnMsg;               // ���š�ȡ����Ϣ�ص�
    pfnDecodedDataCallback fnDecodedStream;         // ������YUV���ݻص�
    void* pUserData;                    // �û�����
    char szReserve[64];                 // ��������
}VIDEO_EZVIZ_REALPLAY_REQ, *PVIDEO_EZVIZ_REALPLAY_REQ;

typedef struct stEzvizRecordReq
{
    int iChannelNo;                         // өʯ�豸ͨ����
	int iHardWareDecode;                    // �Ƿ���GPUӲ�� 0-������ 1-�������������Ӳ�⣬�����Կ���֧�ֵȵ��´���SDK�ڲ��Զ��л�����⣻����Ӳ��ֻ��������ʾ���ܣ������ܼ����ڴ�ռ���ʣ���������ر����󣬽��鲻����Ӳ�⣩
    pfnStreamCallback fnStream;             // �������ݻص�
    pfnMsgCallback fnMsg;                   // ���š�ȡ����Ϣ�ص�
    pfnDecodedDataCallback fnDecodedStream; // ������YUV���ݻص�
    pfnRecordSegmentCallback fnSegment;     // ֱ��өʯ�ط�¼��Ƭ�λص�
    void* pUserData;                        // �û�����
    VIDEO_INT64 i64StartTimeStamp;          // ��ѯ¼��ʼʱ�������λ����
	VIDEO_INT64 i64PlayTimeStamp;           // ¼�񲥷ſ�ʼʱ�������λ����
    VIDEO_INT64 i64EndTimeStamp;            // ��ѯ¼�����ʱ�������λ����
    char szReserve[64];                     // ��������
}VIDEO_EZVIZ_RECORDPLAY_REQ, *PVIDEO_EZVIZ_RECORDPLAY_REQ;

typedef struct stDownloadReq
{
	const char* appkey;					//��������ak,sk
	const char* secretkey;
    pfnDownloadCallback fnDownload;     // ���ؽ��Ȼص�
    void* pUserData;                    // �û�����
    VIDEO_INT64 i64FileMaxSize;         // ¼��ְ���С
    VIDEO_INT64 i64RecordSize;          // ¼���ܴ�С��������ѯ�ط�URLʱ��ѯ���ĸ�¼��Ƭ�δ�С֮��
    VIDEO_INT64 i64StartTimeStamp;      // ¼�����ؿ�ʼʱ�䣬������ѯ�ط�URLʱ�Ĳ�ѯ��ʼʱ�������λ����
    VIDEO_INT64 i64EndTimeStamp;        // ¼�����ؽ���ʱ�䣬������ѯ�ط�URLʱ�Ĳ�ѯ����ʱ�������λ����
    char szReserve[64];             	// ¼�����ͣ���䡰0�������-��ͨ¼�����أ���1��-¼��ת��װ�������Ƶ����Ƶ��֧����ص���֧����Ϣ ��2�� - ¼��ת��װ������Ƶ����Ƶ��֧��ʱ����ת��װ���� ��3��-¼��ת��װ�������Ƶ��֧����ֻת��Ƶ�������ƵҲ��֧����ص���֧����Ϣ ��4��-���öϵ����� ����ֵ - �������󣨶���ָ��¼��ת��װ�����öϵ�������Ŀǰ��֧�ֺ���SDKЭ�顢EHOMEЭ������豸�����������Э�������豸����ص���֧�ֵ���Ϣ�����ڶϵ�������ֻ֧��δת��װ��¼�񣻵�¼������ʱ�����Ȳ�ѯ�豸����Э�飬�Ǻ���SDK��EHOMEЭ�鲻������䡰0�����ɣ�ת��װ�ǽ���Ƶת���ɱ�׼MP4�ļ���������ͨ�ò������ϲ��ţ��粻ת��װ����Ҫר�ò��������ţ����SDK�����豸���ص�¼����Ҫ�󻪲�����������SDKЭ��/EHOMEЭ������¼����Ҫ�������������ţ�
}VIDEO_DOWNLOAD_REQ, *PVIDEO_DOWNLOAD_REQ;

typedef struct stTalkReq
{
	const char* appkey;					//��������ak,sk
	const char* secretkey;
	pfnMsgCallback fnMsg;				// �����Խ���Ϣ�����ڻص������Խ�ȡ����Ϣ���粻��Ҫ�ɴ�NULL��
	void* pUserData;					// �û����ݣ�����fnMsg�ص���͸����ȥ���粻��Ҫ�ɴ�NULL��
	char szReserve[64];					// Ԥ������
}VIDEO_TALK_REQ,*PVIDEO_TALK_REQ;


typedef struct stVideoDetailInfo
{
    int iWidth;                         // ��Ƶͼ����
    int iHeight;                        // ��Ƶͼ��߶�
    int iEncodeType;                    // ��������  1-H264 2-MPEG2_PS 3-MPEG4 4-H265 5-GB28181 6-raw 7-vag 8-dahua 9-smartH264 10-smartH265
    int iEncapsulationType;             // ��װ����  1-ps 2-ts 3-rtp 4-raw 5-rtp + ps
    VIDEO_INT64 i64FrameRate;           // ֡��    
    char szReserve[64];                 // ��������
	float fCodeRate;                    // ���ʣ�V1.2.0������
}VIDEO_DETAIL_INFO, *PVIDEO_DETAIL_INFO;

typedef struct stOSDInfo
{
    int iBold;                  // �����ַ����Ƿ���� 1-���� 0-�Ǵ���
    int ix;                     // �����ַ�����벥�Ŵ������Ͻ����ĺ�����
    int iy;                     // �����ַ�����벥�Ŵ������Ͻ�����������
    int iFontSize;              // �����С
    int iAlignType;             // ���뷽ʽ��0-����� 1-���ж��� 2-�Ҷ���
    VIDEO_INT64 i64Color;       // �ַ���ɫ��Windows��ʹ��RGB������ɫֵ
    char szReserve[64];         // ��������
}VIDEO_OSD_INFO, *PVIDEO_OSD_INFO;

typedef struct stRectangleInfo
{
    int iLeftX;                 // ���϶��������
    int iLeftY;                 // ���϶���������
    int iRightX;                // ���¶��������
    int iRightY;                // ���¶���������
    VIDEO_INT64 i64Color;     // ������ɫ��Windows��ʹ��RGB������ɫֵ
    int iLineWidth;                // ������ϸ
    char szReserve[64];          // ��������
}VIDEO_RECTANGLE_INFO, *PVIDEO_RECTANGLE_INFO;

typedef struct stDisplayInfo
{
    float fx;                 // ����ڲ��Ŵ������϶��γɾ��ε�����ˮƽλ�ã���Բ��Ŵ������Ͻǣ�
    float fy;                 // ����ڲ��Ŵ������϶��γɾ��ε����Ĵ�ֱλ�ã���Բ��Ŵ������Ͻǣ�
    float fWidth;             // ����ڲ��Ŵ������϶��γɾ��εĿ��
    float fHeight;            // ����ڲ��Ŵ������϶��γɾ��εĸ߶�
    int iOperType;           // 0-��С 1-�Ŵ�
	bool bMove;              //true-ƽ�Ƶ��ӷŴ�false-�������ӷŴ�
    char szReserve[64];      // ��������
}VIDEO_DISPLAY_INFO, *PVIDEO_DISPLAY_INFO;

typedef struct stSmallEagleRotateInfo
{
    float fx;                 // x����
    float fy;                 // y����
    float fz;                 // z����
    float fv;                 // �Ŵ���Сֵ������0.0��Ŵ󣬷�����С
    char szReserve[64];      // ��������
}VIDEO_SMALLEAGLEROTATE_INFO, *PVIDEO_SMALLEAGLEROTATE_INFO;

////////////////////////// �ӿڶ��� /////////////////////////////
// SDK��ʼ��
// pszEvn��������������NULL����
// ��ע����һ�μ��ɣ���ʼ���ɹ�������ظ���ֱ�ӷ��سɹ�
// �ɹ�����VIDEO_ERR_SUCCESS��ʧ�ܷ���VIDEO_ERR_FAIL��ʧ����ͨ��Video_GetLastError��ѯ������
VIDEOSDK_DECLARE int Video_Init(_IN_ const char* pszEvn);

// SDK����ʼ��
// ��ע����һ�μ��ɣ�����ʼ���ɹ�������ظ���ֱ�ӷ��سɹ�
// �ɹ�����VIDEO_ERR_SUCCESS��ʧ�ܷ���VIDEO_ERR_FAIL��ʧ����ͨ��Video_GetLastError��ѯ������
VIDEOSDK_DECLARE int Video_Fini();

// ͬ����ʼ��ƵԤ����֧��ȡʵʱ�����ص�ȡ���벥�ŵ���Ϣ���Լ��ص�YUV���ݣ���Ҫ�������������ָ����
// pszUrl��Ԥ��URL��ÿ��Ԥ����Ҫ���²�ѯURL
// hWnd����ƵԤ����Windows���ھ��
// pstPlayReq��������������������������ṹ�嶨��
// ͬ�����ؽ�����ɹ����ش���0��Ԥ�������ʧ�ܷ���VIDEO_ERR_FAIL��ʧ����ͨ��Video_GetLastError��ѯ������
VIDEOSDK_DECLARE VIDEO_INT64 Video_StartPreview(_IN_ const char* pszUrl, _IN_ void* hWnd, _IN_ PVIDEO_PLAY_REQ pstPlayReq);

// �첽��ʼ��ƵԤ����֧��ȡʵʱ�����ص�ȡ���벥�ŵ���Ϣ���Լ��ص�YUV���ݣ���Ҫ�������������ָ����
// pszUrl��Ԥ��URL��ÿ��Ԥ����Ҫ���²�ѯURL
// hWnd����ƵԤ����Windows���ھ��
// pstPlayReq��������������������������ṹ�嶨��
// �첽���ؽ�����ɹ����ش���0��Ԥ�������ʧ�ܷ���VIDEO_ERR_FAIL��ʧ����ͨ��Video_GetLastError��ѯ�����룻����ֵֻ��ʾ�����첽����Ľ������������ȡ������Ľ����ȡ���������ɹ����ο���Ϣ�ص��еġ��첽����ȡ������ɹ����롰�첽����ȡ������ʧ�ܡ���Ϣ
VIDEOSDK_DECLARE VIDEO_INT64 Video_StartAsynPreview(_IN_ const char* pszUrl, _IN_ void* hWnd, _IN_ PVIDEO_PLAY_REQ pstPlayReq);

// ֹͣԤ����ֹͣȡ����ֹͣ�ص���Ϣ��ֹͣ�ص�YUV���ݡ�ֱֹͣ��Ԥ����
// i64PlayHandle��Ԥ���������Դ��Video_StartPreview��Video_StartEzvizPreview����ֵ
// �ɹ�����VIDEO_ERR_SUCCESS��ʧ�ܷ���VIDEO_ERR_FAIL��ʧ����ͨ��Video_GetLastError��ѯ������
VIDEOSDK_DECLARE int Video_StopPreview(_IN_ VIDEO_INT64 i64PlayHandle);

// ��ʱ�ط�
// i64PlayHandle:Ԥ���������Դ��Video_StartPreview����ֵ
// iCtrlType:��ʱ�طſ��Ʋ�����0-���뼴ʱ�ط� 1-�˳���ʱ�طţ�����ֵ-ʧ��
// ��ע��Ԥ����ʱ�ط���ָ��ʹ��Ԥ���Ĵ��ڲ���Ԥ�������л���������������Ƿ񻺴棬������ٿ���VideoSDK.ini�����ļ�����������������ļ��嵥��������Ĭ�Ͽ������棬����5M��������������ļ����ò����棬����˽ӿڽ��뼴ʱ�طŻᵼ��ʧ�ܣ�������Ϊ��֧�֡�
// �ɹ�����VIDEO_ERR_SUCCESS��ʧ�ܷ���VIDEO_ERR_FAIL��ʧ����ͨ��Video_GetLastError��ѯ������
VIDEOSDK_DECLARE int Video_InstantPlay(_IN_ VIDEO_INT64 i64PlayHandle, _IN_ int iCtrlType);

// ���漴ʱ�ط�
// i64PlayHandle:Ԥ���������Դ��Video_StartPreview����ֵ
// pszFileName:¼���ļ�����·���ļ����ƣ���׺�����ǡ�mp4�����硰E:\\test.mp4����·�����ļ������в��ܺ��������ַ���·����Ŀ¼����ȫ�ǿո��ַ�������Ӣ���µġ�*������ | ���Լ�Ӣ���µġ� ? ���������ַ�����
// recordType��¼�����ͣ�0-��ת��װ��1-¼��ת��װ�����Ƶ����Ƶ��֧���򷵻ش��� 2-¼��ת��װ����Ƶ����Ƶ��֧��ʱ����ת��װ���� 3-¼��ת��װ�����Ƶ��֧����ֻת��Ƶ ����ֵ-��������1~3��Ժ������������ǰ��Ƶ�ǷǺ��������ӿڷ��ز�֧�֣�ָ��0ʱ�ýӿ�Ϊͬ���ӿڣ�ָ��1~3Ϊ�첽�ӿڣ���������ͨ����Ϣ�ص��������������Ԥ����Ϣ�ص�
// ��ע�����뼴ʱ�طź���˽ӿڱ��漴ʱ�طţ����δ���뼴ʱ�طŵ��˽ӿڽ�����ʧ�ܣ�������Ϊ�������򲻶�
// ���ָ����ת��װ����û��ת��װ��ɣ�ֻ�е��˳�ʱ��ʱ�ط�ʱ�Ż����ת��װ
// �ɹ�����VIDEO_ERR_SUCCESS��ʧ�ܷ���VIDEO_ERR_FAIL��ʧ����ͨ��Video_GetLastError��ѯ������
VIDEOSDK_DECLARE int Video_SaveInstantPlay(_IN_ VIDEO_INT64 i64PlayHandle, _IN_ const char* pszAbsoluteFileName, _IN_ int recordType);

// ��ѯ��ʱ�ط���ʱ��
// i64PlayHandle��Ԥ���������Դ��Video_StartPreview�ķ���ֵ
// ��ע�����뼴ʱ�طź���˽ӿڻ�ȡ��ʱ�ط���ʱ�������δ���뼴ʱ�طŵ��˽ӿڽ�����ʧ�ܣ�������Ϊ�������򲻶�
// �ɹ����ش��ڵ���0����ʱ����ʧ�ܷ���VIDEO_ERR_FAIL����λ���롣�ӿڷ���ʧ��ͨ������Video_GetLastError��ȡ������
VIDEOSDK_DECLARE VIDEO_INT64 Video_GetInstantPlayDuration(_IN_ VIDEO_INT64 i64PlayHandle);

// ��ѯ��ʱ�ط��Ѳ���ʱ��
// i64PlayHandle��Ԥ���������Դ��Video_StartPreview�ķ���ֵ
// ��ע�����뼴ʱ�طź���˽ӿڻ�ȡ��ʱ�ط���ʱ�������δ���뼴ʱ�طŵ��˽ӿڽ�����ʧ�ܣ�������Ϊ�������򲻶�
// �ɹ����ش��ڵ���0���Ѳ���ʱ����ʧ�ܷ���VIDEO_ERR_FAIL����λ���롣�ӿڷ���ʧ��ͨ������Video_GetLastError��ȡ������
VIDEOSDK_DECLARE VIDEO_INT64 Video_GetInstantPlayedTime(_IN_ VIDEO_INT64 i64PlayHandle);

// ͬ������¼��طš����ţ�֧��ȡ����¼�������ص�ȡ���벥�ŵ���Ϣ���Լ��ص�YUV���ݣ���Ҫ�������������ָ����
// pszUrl���ط�URL
// hWnd������¼�����Ż򵹷ŵ�Window���ھ��
// i64StartTimeStamp������ʱΪ��ѯ�ط�URLʱ�Ŀ�ʼʱ���������ʱΪ��ѯ�ط�URLʱ�Ľ���ʱ�������λ����
// i64EndTimeStamp������ʱΪ��ѯ�ط�URLʱ�Ľ���ʱ���������ʱΪ��ѯ�ط�URLʱ�Ŀ�ʼʱ�������λ����
// pstPlayReq�����������������ϸ��������ṹ�嶨��
// ͬ�����ؽ�����ɹ����ش���0�Ĳ��ž����ʧ�ܷ���VIDEO_ERR_FAIL��ʧ����ͨ��Video_GetLastError��ѯ������
VIDEOSDK_DECLARE VIDEO_INT64 Video_StartPlayback(_IN_ const char* pszUrl, _IN_ void* hWnd, _IN_ VIDEO_INT64 i64StartTimeStamp, _IN_ VIDEO_INT64 i64EndTimeStamp, _IN_ PVIDEO_PLAY_REQ pstPlayReq);

// �첽����¼��طš����ţ�֧��ȡ����¼�������ص�ȡ���벥�ŵ���Ϣ���Լ��ص�YUV���ݣ���Ҫ�������������ָ����
// pszUrl���ط�URL
// hWnd������¼�����Ż򵹷ŵ�Window���ھ��
// i64StartTimeStamp������ʱΪ��ѯ�ط�URLʱ�Ŀ�ʼʱ���������ʱΪ��ѯ�ط�URLʱ�Ľ���ʱ�������λ����
// i64EndTimeStamp������ʱΪ��ѯ�ط�URLʱ�Ľ���ʱ���������ʱΪ��ѯ�ط�URLʱ�Ŀ�ʼʱ�������λ����
// pstPlayReq�����������������ϸ��������ṹ�嶨��
// �첽���ؽ�����ɹ����ش���0�Ĳ��ž����ʧ�ܷ���VIDEO_ERR_FAIL��ʧ����ͨ��Video_GetLastError��ѯ�����룻����ֵֻ��ʾ�����첽����Ľ������������ȡ������Ľ����ȡ���������ɹ����ο���Ϣ�ص��еġ��첽����ȡ������ɹ����롰�첽����ȡ������ʧ�ܡ���Ϣ
VIDEOSDK_DECLARE VIDEO_INT64 Video_StartAsynPlayback(_IN_ const char* pszUrl, _IN_ void* hWnd, _IN_ VIDEO_INT64 i64StartTimeStamp, _IN_ VIDEO_INT64 i64EndTimeStamp, _IN_ PVIDEO_PLAY_REQ pstPlayReq);

// ֹͣ����¼�����š����ţ�ֹͣȡ����ֹͣ�ص���Ϣ��ֹͣ�ص�YUV���ݣ�
// i64PlayHandle������¼�񲥷ž������Դ��Video_StartPlayback�ķ���ֵ
// �ɹ�����VIDEO_ERR_SUCCESS��ʧ�ܷ���VIDEO_ERR_FAIL��ʧ����ͨ��Video_GetLastError��ѯ������
VIDEOSDK_DECLARE int Video_StopPlayback(_IN_ VIDEO_INT64 i64PlayHandle);

// ��ѯ¼��طŵ�ǰ����ʱ���
// i64PlayHandle:����¼�񲥷ž������Դ��Video_StartPlayback��Video_StartEzvizPlayback�ķ���ֵ
// �ɹ����ش��ڵ���0�ĵ�ǰ�ط�ʱ�����ʧ�ܷ���VIDEO_ERR_FAIL����λ���롣�ӿڷ���ʧ��ͨ������Video_GetLastError��ȡ������
VIDEOSDK_DECLARE VIDEO_INT64 Video_GetCurrentPlayTime(_IN_ VIDEO_INT64 i64PlayHandle);

//------------------ֱ��өʯ-------------------
// ��ʼ��өʯֱ��
// pszEnv����өʯƽ̨�����APPKey
// pszEzvizToken����өʯƽ̨��ȡ��token
// fnEzvizToken������өʯtoken�ص�
// pUserData���û�����
// ��ע����Ҫ��SDK��ʼ�����ٳ�ʼ��ֱ��өʯ����һ�μ��ɣ���ʼ���ɹ���������ʹ����ͬ��өʯAPPKey��token��ʼ���ӿڷ��سɹ����������������»ص������ʹ�ò�ͬ��APPKey��token������ʧ�ܣ����ʹ�÷��Լ���ʱ����өʯtoken��fnEzvizToken��pUserData�ɴ���NULL����ʱ������֪ͨөʯtoken����������Ϣ
// �ɹ�����VIDEO_ERR_SUCCESS��ʧ�ܷ���VIDEO_ERR_FAIL��ʧ����ͨ��Video_GetLastError��ѯ������
VIDEOSDK_DECLARE int Video_InitEzviz(_IN_ const char* pszEzvizAppkey, _IN_ const char* pszEzvizToken, _IN_ pfnUpdataEzvizTokenCallback fnEzvizToken, _IN_ void* pUserData);

// өʯ����ʼ��
VIDEOSDK_DECLARE void Video_UninitEzviz();

// ����өʯtoken����өʯtoken����ʧЧʱ��ͨ��pfnUpdataEzvizTokenCallback�ص�����өʯtoken��Ϣ��ʹ�÷����ж�ʱ����өʯtoken��ʹ�÷���ѯөʯtoken��ͨ���˽ӿڸ���өʯtoken
// pszEzvizToken����өʯƽ̨��ȡ��token
// �ɹ�����VIDEO_ERR_SUCCESS��ʧ�ܷ���VIDEO_ERR_FAIL��ʧ����ͨ��Video_GetLastError��ѯ������
VIDEOSDK_DECLARE int Video_UpdateEzvizToken(_IN_ const char* pszEzvizToken);

// ֱ��өʯԤ����ȡ��
// hWnd��Ԥ�����ھ��
// pszDevSerial��өʯ�豸���к�
// pszSafeKey����Ƶ������Կ����δ���������NULL��
// pstPlayReq��ֱ��өʯԤ�������������ϸ�������ṹ�嶨��
VIDEOSDK_DECLARE VIDEO_INT64 Video_StartEzvizPreview(_IN_ void* hWnd, _IN_ const char* pszDevSerial, _IN_ const char* pszSafeKey, _IN_ PVIDEO_EZVIZ_REALPLAY_REQ pstEzvizRealPlayReq);

// ֱ��өʯ�طš�ȡ��
// hWnd���طŴ��ھ��
// pszDevSerial:өʯ�豸���к�
// pszSafeKey����Ƶ������Կ����δ���������NULL.
// pszPlayReq��ֱ��өʯ�ط��������
VIDEOSDK_DECLARE VIDEO_INT64 Video_StartEzvizPlayback(_IN_ void* hWnd, _IN_ const char* pszDevSerial, _IN_ const char* pszSafeKey, _IN_ PVIDEO_EZVIZ_RECORDPLAY_REQ pstEzvizRecordReq);

// ֱ��өʯ�����Խ�
// pszDevSerial:өʯ�豸���к�
// iChannelNo:өʯ�豸ͨ����
// pszFileName:�����Խ�������Ƶ�ľ���·���ļ����ƣ�ֻ֧��wav��׺���硰D:\test.wav�����粻��Ҫ¼�����ò����봫NULL��·�����ļ����Ʋ��ܰ��������ַ�����Ӣ���µġ�*������|���Լ�Ӣ���µġ�?���������⣬·�������á�.���͡�..������ʱ��֧�ֱ�����Ƶ�ļ����ܣ��ò��������NULL��
// fnMsg:�����Խ���Ϣ�ص������������ڻص������Խ�ȡ����Ϣ���粻��Ҫ�ɴ�NULL
// pUserData:�û����ݣ�����fnMsg�ص���͸����ȥ���粻��Ҫ�ɴ�NULL
// �ɹ�����VIDEO_ERR_SUCCESS��ʧ�ܷ���VIDEO_ERR_FAIL��ʧ����ͨ��Video_GetLastError��ѯ������
VIDEOSDK_DECLARE int Video_StartEzvizTalk(_IN_ const char* pszDevSerial, _IN_ int iChannelNo, _IN_ const char* pszFileName, _IN_ pfnMsgCallback fnMsg, _IN_ void* pUserData);

//-----------�ļ�����--------------
// ��ʼ�ļ�����
// pszFileName������·��mp4�ļ�����
// hWnd���ļ����Ŵ��ھ��
// pstFilePlayReq���ļ�������������ṹ�壬����ص���Ϣ���ɴ�NULL
// ��ע����֧�ֲ���ͨ������SDKЭ�顢Ehome/ISUPЭ�顢ONVIFЭ�顢��SDKЭ�顢����Э�顢өʯ������豸����¼��¼�������¼�����ص��ļ�
// �ɹ����ش���0���ļ����ž����ʧ�ܷ���VIDEO_ERR_FAIL��ʧ����ͨ��Video_GetLastError��ѯ������
VIDEOSDK_DECLARE VIDEO_INT64 Video_StartFilePlay(_IN_ const char* pszFileName, _IN_ void* hWnd, _IN_ PVIDEO_FILEPLAY_REQ pstFilePlayReq);

// ֹͣ�ļ�����
// i64PlayHandle���ļ����ž������Դ��Video_StartFilePlay�ķ���ֵ
// �ɹ�����VIDEO_ERR_SUCCESS��ʧ�ܷ���VIDEO_ERR_FAIL��ʧ����ͨ��Video_GetLastError��ѯ������
VIDEOSDK_DECLARE int Video_StopFilePlay(_IN_ VIDEO_INT64 i64PlayHandle);

// ��ѯ�ļ�������ʱ��
// i64PlayHandle:�ļ����ž������Դ��Video_StartFilePlay�ķ���ֵ
// �ɹ����ش��ڵ���0����ʱ����ʧ�ܷ���VIDEO_ERR_FAIL����λ���롣�ӿڷ���ʧ��ͨ������Video_GetLastError��ȡ������
VIDEOSDK_DECLARE VIDEO_INT64 Video_GetFilePlayDuration(_IN_ VIDEO_INT64 i64PlayHandle);

// ��ѯ�ļ��Ѳ���ʱ��
// i64PlayHandle���ļ����ž������Դ��Video_StartFilePlay�ķ���ֵ
// �ɹ����ش��ڵ���0���Ѳ���ʱ����ʧ�ܷ���VIDEO_ERR_FAIL����λ���롣�ӿڷ���ʧ��ͨ������Video_GetLastError��ȡ������
VIDEOSDK_DECLARE VIDEO_INT64 Video_GetFilePlayedTime(_IN_ VIDEO_INT64 i64PlayHandle);

//-----------------¼������-----------------
// ��ʼ¼������
// pszUrl:����ȡ��URL
// pszFileName:¼���ļ�����¼�����ƣ���ָ����׺mp4���硰E:\test.mp4����pszFileNameΪansi�����ַ�����·�����ļ����Ʋ��ܰ��������ַ�����Ӣ���µġ�*������|���Լ�Ӣ���µġ�?���������⣬·�������á�.���͡�..����¼�����ز�֧�����ص�����λ��,ֻ�����ص����ء�����pstDownloadReq��ָ���ϵ�����ʱ���봫���ϴ�¼������������ɵ�һ���ļ��ľ���·���ļ����ƣ������֧�ֻ�ͨ���ص�������Ϣ
// pstDownloadReq:¼�����������������ϸ��������ṹ�嶨��
// ��ע��֧��ͨ�������ļ�VideoSDK.int���ã��Ǻ�����ʱ��ȡ�������С��������ʱ�Ƿ�ת��װ��֧����ͨ����������
// �ɹ����ش���0�Ĳ��ž����ʧ�ܷ���VIDEO_ERR_FAIL��ʧ����ͨ��Video_GetLastError��ѯ������
VIDEOSDK_DECLARE VIDEO_INT64 Video_StartDownload(_IN_ const char* pszUrl, _IN_ const char* pszFileName, _IN_ PVIDEO_DOWNLOAD_REQ pstDownloadReq);

// ֹͣ����
// i64DownloadHandle��¼�����ؾ������Դ��Video_StartDownload�ķ���ֵ
// �ɹ�����VIDEO_ERR_SUCCESS��ʧ�ܷ���VIDEO_ERR_FAIL��ʧ����ͨ��Video_GetLastError��ѯ������
VIDEOSDK_DECLARE int Video_StopDownload(_IN_ VIDEO_INT64 i64DownloadHandle);

//-----------------ͨ�ýӿ�--------------------
// ��ʼ����¼�񣬶���ͬһ·��ͬһʱ��ֻ֧��һ·����¼�񣬷��򷵻ز�֧��
// i64PlayHandle�����ž����Video_StartPlayback��Video_StartPreview��Video_StartEzvizPreview��Video_StartEzvizPlayback�ӿڷ���
// pszFileName:¼���ļ�����·�����ƣ���ָ����׺mp4���硰E:\test.mp4����pszFileNameΪansi�����ַ�����·�����ļ����Ʋ��ܰ��������ַ�����Ӣ���µġ�*������|���Լ�Ӣ���µġ�?���������⣬·�������á�.���͡�..����
// i64FileMaxSize���ְ���С��λ���ֽڣ�����С��5M������5M���㣻�ְ����������򣺡�E:\test-1.mp4����...��E:\test-n.mp4����n��ʾ����E:\test.mp4����ĵ�n���ְ�
// recordType��¼�����ͣ�0-��ת��װ��1-¼��ת��װ�����Ƶ����Ƶ��֧���򷵻ش��� 2-¼��ת��װ����Ƶ����Ƶ��֧��ʱ����ת��װ����ǰ���Ǵ�����Ƶ����Ƶ���ݣ� 3-¼��ת��װ�����Ƶ��֧����ֻת��Ƶ ����ֵ-��������1~3��Ժ������������ǰ��Ƶ�ǷǺ��������ӿڷ��ز�֧�֣�
// ��Щ�豸���Ļ��������Ƶ����֧��ת��װ����ʱֻ����Ƶ��ת��װ
// ��Щ�豸��������֧��ת��װ������豸������ʱ����ת��װ
// �ɹ�����VIDEO_ERR_SUCCESS��ʧ�ܷ���VIDEO_ERR_FAIL��ʧ����ͨ��Video_GetLastError��ѯ������
VIDEOSDK_DECLARE int Video_StartLocalRecord(_IN_ VIDEO_INT64 i64PlayHandle, _IN_ const char* pszFileName, _IN_ VIDEO_INT64 i64FileMaxSize, _IN_ int recordType);

// ֹͣ����¼��
// �ɹ������������ļ�������ʧ�ܷ���VIDEO_ERR_FAIL��ʧ����ͨ��Video_GetLastError��ѯ������
VIDEOSDK_DECLARE int Video_StopLocalRecord(_IN_ VIDEO_INT64 i64PlayHandle);

//���š����ؿ���
// i64PlayHandle:���ž����Video_StartPlayback��Video_StartPreview��Video_StartEzvizPreview��Video_StartEzvizPlayback�ӿڷ���
// iCtrlType:0-��ͣ 1-�ָ����� 2-��λ���� 3-���ٲ���/���� 4-��ͣ���� 5-�ָ����� 6-��֡����
// i64Param:���Ʋ�������iCtrlType���ʹ��
// �ɹ�����VIDEO_ERR_SUCCESS��ʧ�ܷ���VIDEO_ERR_FAIL��ʧ����ͨ��Video_GetLastError��ѯ������
// ��ע��1-�ָ������ǻָ���1���٣��������ϴεĲ����ٶȣ�2-ʱ��������ɵ��÷���֤���ڿ�ʼ�����ʱ���֮�䣬��λ���룻3-���Ʋ���Ϊ�ٶ�ȡֵ��16��8��4��2��1��-2��-4��-8��-16�������ɿ�������ţ�6-���Ʋ���ȡֵ��0-��֡�� 1-��֡�� 2-�˳���֡
VIDEOSDK_DECLARE int Video_PlayCtrl(_IN_ VIDEO_INT64 i64PlayHandle, _IN_ int iCtrlType, _IN_ VIDEO_INT64 i64Param);

//���������л�
// iPlayHandle:���ž����Video_StartPreview��Video_StartEzvizPreview����
// iAsyn���Ƿ��첽�л���1-�첽��0-ͬ����������첽�л����л��ɹ���Ϣ����Ϣ�ص�����������ӿڷ���ֵ�����Ƿ��л��ɹ���ȡ����ֵ�򷵻�ʧ��
// pszParam�����������л���������ֱ��өʯʱָ���������͵�Ԥ����ȡ��url��ֱ��өʯԤ���л���������ʱ������ΪNULL
// �ɹ�����VIDEO_ERR_SUCCESS��ʧ�ܷ���VIDEO_ERR_FAIL��ʧ����ͨ��Video_GetLastError��ѯ������
// ��ע��ֱ��өʯԤ����ȡ��ʱ��Ĭ���л�����ͬ�ڵ�ǰ�������͵���һ���������͡���ֱ��өʯ������Ԥ��ʱ�����ô˽ӿڽ�Ĭ���л�Ϊ��������ֱ��өʯ������Ԥ��ʱ�����ô˽ӿڽ�Ĭ���л�Ϊ��������
VIDEOSDK_DECLARE int Video_ChangeStreamType(VIDEO_INT64 i64PlayHandle, int iAsyn, const char* pszParam);

// ����ץͼ
// i64PlayHandle:���ž����Video_StartPreview��Video_StartPlayback��Video_StartFilePlay��Video_StartEzvizPreview��Video_StartEzvizPlayback�ӿڷ���
// pszFileName:Ҫ�����ͼƬ����·�������ļ������������ļ�����׺ȷ�������ͼƬ��ʽ��֧��bmp��jpg����������E:/SnapShot/���Լ�ص�.jpg����pszFileNameΪansi�����ַ�����·�����ļ����Ʋ��ܰ��������ַ�����Ӣ���µġ�*������|���Լ�Ӣ���µġ�?���������⣬·�������á�.���͡�..��
// �ɹ�����VIDEO_ERR_SUCCESS��ʧ�ܷ���VIDEO_ERR_FAIL��ʧ����ͨ��Video_GetLastError��ѯ������
VIDEOSDK_DECLARE int Video_PlaySnap(_IN_ VIDEO_INT64 i64PlayHandle, _IN_ const char* pszFileName);

// ��������
// i64PlayHandle:���ž����Video_StartPreview��Video_StartPlayback��Video_StartFilePlay��Video_StartEzvizPreview��Video_StartEzvizPlayback�ӿڷ���
// iCtrlType:�������ͣ�0-�� 1-�رգ�����ֵ-δ���塣
// �ɹ�����VIDEO_ERR_SUCCESS��ʧ�ܷ���VIDEO_ERR_FAIL��ʧ����ͨ��Video_GetLastError��ѯ������
// ��ע������������Ҫ������������Ƶ���ݲ���Ч��
VIDEOSDK_DECLARE int Video_SoundCtrl(_IN_ VIDEO_INT64 i64PlayHandle, _IN_ int iCtrlType);

// ��ȡ����
// i64PlayHandle:���ž����Video_StartPreview��Video_StartPlayback��Video_StartFilePlay��Video_StartEzvizPreview��Video_StartEzvizPlayback�ӿڷ���
// �ɹ���������ֵ��������Χ[0,100]��ʧ�ܷ���VIDEO_ERR_FAIL��ʧ����ͨ��Video_GetLastError��ѯ������
// ��ע����Ҫ�����������Ч��
VIDEOSDK_DECLARE int Video_GetVolume(_IN_ VIDEO_INT64 i64PlayHandle);

// ��������
// i64PlayHandle:���ž����Video_StartPreview��Video_StartPlayback��Video_StartFilePlay��Video_StartEzvizPreview��Video_StartEzvizPlayback�ӿڷ���
// iVolume:����ֵ����Χ[0,100]
// �ɹ�����VIDEO_ERR_SUCCESS��ʧ�ܷ���VIDEO_ERR_FAIL��ʧ����ͨ��Video_GetLastError��ѯ������
// ��ע����Ҫ�����������Ч��
VIDEOSDK_DECLARE int Video_SetVolume(_IN_ VIDEO_INT64 i64PlayHandle, _IN_ int iVolume);

// ���ӷŴ�
// i64PlayHandle:���ž����Video_StartPreview��Video_StartPlayback��Video_StartFilePlay��Video_StartEzvizPreview��Video_StartEzvizPlayback�ӿڷ���
// iCtrlType:��־������ӷŴ����˳����ӷŴ�0-������ӷŴ� 1-�˳����ӷŴ� ����ֵ-��������
// hWnd:������ӷŴ�ʱ��ȫ�����ھ����
// �ɹ�����VIDEO_ERR_SUCCESS��ʧ�ܷ���VIDEO_ERR_FAIL��ʧ����ͨ��Video_GetLastError��ѯ������
// ��ע:Сӥ�۲�֧�ֵ��ӷŴ�
VIDEOSDK_DECLARE int Video_DigitalZoom(_IN_ VIDEO_INT64 i64PlayHandle, _IN_ int iCtrlType, _IN_ void* hWnd);

// ���õ��ӷŴ���ʾ����
// i64PlayHandle:���ž����Video_StartPreview��Video_StartPlayback��Video_StartFilePlay��Video_StartEzvizPreview��Video_StartEzvizPlayback�ӿڷ���
// pstDisplayInfo:���ӷŴ���ʾ�������
// �ɹ�����VIDEO_ERR_SUCCESS��ʧ�ܷ���VIDEO_ERR_FAIL��ʧ����ͨ��Video_GetLastError��ѯ������
// ��ע:������ӷŴ�����õ��ӷŴ���ʾ����
VIDEOSDK_DECLARE int Video_SetDisplayZoom(_IN_ VIDEO_INT64 i64PlayHandle, _IN_ PVIDEO_DISPLAY_INFO pstDisplayInfo);

// �����ַ�����
// i64PlayHandle:���ž����Video_StartPreview��Video_StartPlayback��Video_StartFilePlay��Video_StartEzvizPreview��Video_StartEzvizPlayback�ӿڷ���
// iOSDId:�ַ����ӱ�ʶ����һ�ε���ʱ�봫��0�����»����ϵ��ַ���ʱ�����һ�ε���ʱ���ص�Id
// pszText:�������ַ�����֧�֡�\n�����У��ַ���������512���ֽڣ��糬����ض���ʾ
// pstOSDInfo:�ַ�������Ϣ
// �ɹ����ر��ε��ӵ�id����Idȡֵ���ڵ���0��ʧ�ܷ���VIDEO_ERR_FAIL��ʧ����ͨ��Video_GetLastError��ѯ������
VIDEOSDK_DECLARE int Video_SetOSDText(_IN_ VIDEO_INT64 i64PlayHandle, _IN_ int iOSDId, _IN_ const char* pszText, _IN_ PVIDEO_OSD_INFO pstOSDInfo);

// ������ο����
// i64PlayHandle:���ž����Video_StartPreview��Video_StartPlayback��Video_StartFilePlay��Video_StartEzvizPreview��Video_StartEzvizPlayback�ӿڷ���
// iDrawType:�������ͣ�0-ʵʱԤ����¼��طš���ʱ�طź��ļ�����ָ���Ĵ����ϻ��� 1-���ӷŴ�ָ���Ĵ����ϻ���
// pstRectangleInfo:���ε�����Ϣ
// �ɹ�����VIDEO_ERR_SUCCESS��ʧ�ܷ���VIDEO_ERR_FAIL��ʧ����ͨ��Video_GetLastError��ѯ������
// ��ע:���ӷŴ�ʱʹ�øýӿ��ڻ����ϻ��ƾ��ο��Ա�Ǵ��Ŵ�����
VIDEOSDK_DECLARE int Video_DrawRectangle(_IN_ VIDEO_INT64 i64PlayHandle, _IN_ int iDrawType, _IN_ PVIDEO_RECTANGLE_INFO pstRectangleInfo);


// �����Զ���ͼ�ο����
// i64PlayHandle:���ž����Video_StartPreview��Video_StartPlayback��Video_StartFilePlay��Video_StartEzvizPreview��Video_StartEzvizPlayback�ӿڷ���
// iGraphType:�������ͣ�0-���� 1-ֱ��
// pstRectangleInfo:���ε�����Ϣ
// lineMode �������ߣ��������Ϊ���ڴ�С�仯���ػ棬��1�������ӵģ���0
// �ɹ�����VIDEO_ERR_SUCCESS��ʧ�ܷ���VIDEO_ERR_FAIL��ʧ����ͨ��Video_GetLastError��ѯ������
VIDEOSDK_DECLARE int Video_CustomDraw(_IN_ VIDEO_INT64 i64PlayHandle, _IN_ int iGraphType, _IN_ PVIDEO_RECTANGLE_INFO pstRectangleInfo, _IN_  int lineMode);
// ��ʼ�����Խ�
// pszUrl:�����Խ�URL���ɴ�OpenAPI��ѯ�Խ�URL��ÿ�ζԽ��������²�ѯ�Խ�URL
// pszFileName:�����Խ�������Ƶ�ľ���·���ļ����ƣ�ֻ֧��wav��׺���硰D:\test.wav�����粻��Ҫ¼�����ò����봫NULL��·�����ļ����Ʋ��ܰ��������ַ�����Ӣ���µġ�*������|���Լ�Ӣ���µġ�?���������⣬·�������á�.���͡�..������ʱ��֧�ֱ�����Ƶ�ļ����ܣ��ò��������NULL��
// pstTalkReq:�����Խ��ṹ��
// �ɹ�����VIDEO_ERR_SUCCESS��ʧ�ܷ���VIDEO_ERR_FAIL��ʧ����ͨ��Video_GetLastError��ѯ������
// ��ע��ͬһʱ��ֻ֧��һ·�Խ������޷����������Խ�ʧ�ܻ��������Խ�ͨ����ռ�á�ֻ֧����ǰ���豸�Խ���ǰ��IPC�豸����NVR��֧����ǰ��IPC�豸�Խ�����֧��ֱ����NVR�Խ���ÿ�ζԽ��������²�ѯ�Խ�URL���ݲ�֧�ֱ�����Ƶ�ļ����ܣ�pszFileName���������NULL�������Խ�ֻ֧�ֺ���SDK��EhomeЭ������豸��
VIDEOSDK_DECLARE int Video_StartTalk(_IN_ const char* pszUrl, _IN_ const char* pszFileName, PVIDEO_TALK_REQ pstTalkReq);

// ֹͣ�����Խ�
// �ɹ�����VIDEO_ERR_SUCCESS��ʧ�ܷ���VIDEO_ERR_FAIL���ӿڷ���ʧ�������Video_GetLastError��ȡ�����룬ͨ���������жϳ���ԭ��
VIDEOSDK_DECLARE int Video_StopTalk();

// ��ѯ��Ƶ��ϸ��Ϣ
// i64PlayHandle��ʵʱԤ��������¼�����Ż򵹷ž������Դ��Video_StartPreview��Video_StartPlayback��Video_StartFilePlay����ֵ
// pstVideoDetailInfo����Ƶ��ϸ��Ϣ�ṹ��ָ��
// �ɹ�����VIDEO_ERR_SUCCESS��ʧ�ܷ���VIDEO_ERR_FAIL���ӿڷ���ʧ�������Video_GetLastError��ȡ�����룬ͨ���������жϳ���ԭ��
VIDEOSDK_DECLARE int Video_GetVideoInfo(_IN_ VIDEO_INT64 i64PlayHandle, _OUT_ PVIDEO_DETAIL_INFO pstVideoDetailInfo);

// ˽�����ݿ��ƣ�ָ�����ϵ����ƶ������߿�����ݵĿ��ؿ��ƣ���Ժ������豸��֧�ֺ���SDK��EHOME/ISUP��ONVIF��GB28181Э����룩
// i64PlayHandle�������������Դ��Video_StartPreview��Video_StartPlayback��Video_StartFilePlay�ķ���ֵ
// iPrivateDataType��˽���������ͣ������ʹ�á�|����������������ƣ�0x0001-���ܷ��� 0x0002-�ƶ���� 0x0004-POS��Ϣ����� 0x0008-ͼƬ���� 0x0010-�ȳ�����Ϣ 0x0020-�¶���Ϣ
// iCtrlType����ʾ���ؿ��� 0-��ʾ 1-����
// iParam��һЩ˽���������ʹ��������ͣ���iDataTypeΪ0x0010ʱ����������0x0001-������ʾ 0x0002-����¶� 0x0004-����¶�λ�� 0x0008-����¶Ⱦ��룻��iDataTypeΪ0x0020ʱ����������0x0001-����� 0x0002-�߲��� 0x0004-�����
// ע�����ڲ��漰�����ͣ����������ͣ��ģ�֧�ָ���˽���������͵ġ�|�����㣬�����漰�����͵ģ���һ��һ���������ͽ��п��ƣ�ͬһ���͵�������֧�֡�|�����㣻iDataTypeΪ0x0010��0x0020ʱ��Ҫ�ȳ����豸֧�֣�����������ͨ�豸����֧�֣�����Ҫ�豸������
// �ɹ�����VIDEO_ERR_SUCCESS��ʧ�ܷ���VIDEO_ERR_FAIL��ʧ����ͨ��Video_GetLastError��ѯ�����룬�Ǻ����豸��֧�ֻᣬĿǰ�޷������Ƿ�֧��
VIDEOSDK_DECLARE int Video_PrivateDataCtrl(_IN_ VIDEO_INT64 iPlayHandle, _IN_ int iPrivateDataType, _IN_ int iCtrlType, _IN_ int iParam);

// Сӥ�۲��ſ���
// i64PlayHandle�������������Դ��Video_StartPreview��Video_StartPlayback��Video_StartFilePlay�ķ���ֵ
// iMode��Сӥ�ۻ�����ʾģʽ��0-�˻�����ʾ 1-��״������ʾ
// �ɹ�����VIDEO_ERR_SUCCESS��ʧ�ܷ���VIDEO_ERR_FAIL��ʧ����ͨ��Video_GetLastError��ѯ������
// ��ע����֧�ֺ���SDKЭ�������豸�����������豸����Э�����������ͨ�豸���������ָ��Сӥ�ۻ�����ʾģʽ����Ĭ����ʾ4���档Сӥ���豸ʵʱԤ����֧�ּ�ʱ�طţ�����¼��طŲ�֧�ֵ��š���֧�ֵ�֡��
VIDEOSDK_DECLARE int Video_SetSmallEagleEyeMode(_IN_ VIDEO_INT64 i64PlayHandle, _IN_ int iMode);

// Сӥ����״����ʱ��ת����
// i64PlayHandle�������������Դ��Video_StartPreview��Video_StartPlayback��Video_StartFilePlay�ķ���ֵ
// pstRotateInfo��Сӥ����״������ת����
// �ɹ�����VIDEO_ERR_SUCCESS��ʧ�ܷ���VIDEO_ERR_FAIL��ʧ����ͨ��Video_GetLastError��ѯ������
VIDEOSDK_DECLARE int Video_SetSmallEagleEyeRotate(_IN_ VIDEO_INT64 i64PlayHandle, _IN_ PVIDEO_SMALLEAGLEROTATE_INFO pstRotateInfo);

// ˢ�²���
// i64PlayHandle�������������Դ��Video_StartPreview ��Video_StartPlayback��Video_StartFilePlay��Video_StartEzvizPreview��Video_StartEzvizPlayback����ֵ
// �ɹ�����VIDEO_ERR_SUCCESS��ʧ�ܷ���VIDEO_ERR_FAIL��ʧ����ͨ��Video_GetLastError��ѯ������
VIDEOSDK_DECLARE int Video_RefreshPlay(VIDEO_INT64 i64PlayHandle);

// ��ȡ������
VIDEOSDK_DECLARE int Video_GetLastError();

// �첽��ʼ�����Խ�
// pszUrl:�����Խ�URL���ɴ�OpenAPI��ѯ�Խ�URL��ÿ�ζԽ��������²�ѯ�Խ�URL
// pszFileName:�����Խ�������Ƶ�ľ���·���ļ����ƣ�ֻ֧��wav��׺���硰D:\test.wav�����粻��Ҫ¼�����ò����봫NULL��·�����ļ����Ʋ��ܰ��������ַ�����Ӣ���µġ�*������|���Լ�Ӣ���µġ�?���������⣬·�������á�.���͡�..������ʱ��֧�ֱ�����Ƶ�ļ����ܣ��ò��������NULL��
// fnMsg:�����Խ���Ϣ�����ڻص������Խ�ȡ����Ϣ���粻��Ҫ�ɴ�NULL��
// pUserData:�û����ݣ�����fnMsg�ص���͸����ȥ���粻��Ҫ�ɴ�NULL��
// �첽���ؽ�����ɹ�����VIDEO_ERR_SUCCESS��ʧ�ܷ���VIDEO_ERR_FAIL��ʧ����ͨ��Video_GetLastError��ѯ�����룻����ֵֻ��ʾ�����첽����Ľ������������ȡ������Ľ����ȡ���������ɹ����ο���Ϣ�ص��еġ��첽����ȡ������ɹ����롰�첽����ȡ������ʧ�ܡ���Ϣ
// ��ע��ͬһʱ��ֻ֧��һ·�Խ������޷����������Խ�ʧ�ܻ��������Խ�ͨ����ռ�á�ֻ֧����ǰ���豸�Խ���ǰ��IPC�豸����NVR��֧����ǰ��IPC�豸�Խ�����֧��ֱ����NVR�Խ���ÿ�ζԽ��������²�ѯ�Խ�URL���ݲ�֧�ֱ�����Ƶ�ļ����ܣ�pszFileName���������NULL�������Խ�ֻ֧�ֺ���SDK��EhomeЭ������豸��
VIDEOSDK_DECLARE int Video_StartAsynTalk(_IN_ const char* pszUrl, _IN_ const char* pszFileName, PVIDEO_TALK_REQ pstTalkReq);

#endif  // HIK_VIDEOSDK_H