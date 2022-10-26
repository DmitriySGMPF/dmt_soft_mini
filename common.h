
#pragma once//ֻ����һ�η�ֹ�ظ�����


#ifndef BODYCAMDLL_API
#ifdef BODYCAMDLL_EXPORTS
#define BODYCAMDLL_API  __declspec(dllexport)
#else
#define BODYCAMDLL_API   __declspec(dllimport)
#endif
#define  BCHandle  void
#endif

#define WINAPI	__stdcall
typedef enum
{
	PARATYPE_LISTSUM=1,
	PARATYPE_DISK,
}PARA_TYPE;
typedef int (WINAPI *PFCALLBACK)(/*PARA_TYPE*/int paratype,int paraval) ;



#if 0
#define BC_SUCCESS	0
#define BC_FAILED	-1
#else
#define BC_SUCCESS	1
#define BC_FAILED	0
#endif

typedef enum BODYCAMDLL_API
{
	FS_FAT32=1,
	FS_EXFAT,
}FSTYPE_E;

#ifndef DEV_INFO
#if 0
typedef struct //DYCAMDLL_API
{
	char cSerial[7];   /*ִ����¼�ǲ�Ʒ��ţ�����Ϊ��*/
	char userNo[6];    /*ִ����¼��ʹ���߾��ţ�����Ϊ��*/
	char userName[32]; /*ִ����¼��ʹ��������������ϵͳʹ�þ��Ź���ʱ��Ϊ��*/
	char unitNo[12];   /*ִ����¼��ʹ���ߵ�λ��ţ�����ϵͳʹ�þ��Ź���ʱ��Ϊ��*/
	char unitName[32]; /*ִ����¼��ʹ���ߵ�λ���ƣ�����ϵͳʹ�þ��Ź���ʱ��Ϊ��*/
}ZFY_INFO;
#else
typedef struct /*DYCAMDLL_API*/
{
	char cSerial[8];   /*ִ����¼�ǲ�Ʒ���(�������ã�ֻ�ܻ�ȡ)����ȡʱ����Ϊ��*/
	char userNo[7];    /*ִ����¼��ʹ���߾��ţ�����Ϊ��*/
	char userName[33]; /*ִ����¼��ʹ��������������ϵͳʹ�þ��Ź���ʱ��Ϊ��*/
	char unitNo[13];   /*ִ����¼��ʹ���ߵ�λ��ţ�����ϵͳʹ�þ��Ź���ʱ��Ϊ��*/
	char unitName[33]; /*ִ����¼��ʹ���ߵ�λ���ƣ�����ϵͳʹ�þ��Ź���ʱ��Ϊ��*/
}ZFY_INFO;
#endif
#define DEV_INFO  ZFY_INFO
#endif

typedef struct
{
	BCHandle *dev;    //�豸�������
	int ListIndex;	// �豸���б��е�����ֵ
	int UsbBusNum;	//USB ���ߺ�
	int bUDisk;		// �Ƿ��Ѿ��γ�U�̡�1-���γ�U�̣�0-δ�γ�U��
	int bNewDevFlag;	// �Ƿ��¼�����豸
	char SN[16];         // �豸ID���豸Ψһ��ID,���ɸ���
	char IDCode[8];	// �豸ʶ���롣�豸���ͱ��룬���ɸ���
	char ExFlag[16];
	short Pid;
	short Vid;
}DEVLIST_INFO;

typedef enum
{
	UMS_ACT_BEGIN = -1,
	UMS_ACT_GET,
	UMS_ACT_SET,
	UMS_ACT_SGET,			// Set and Get		
	UMS_ACT_ADD,
	UMS_ACT_DEL,
	UMS_ACT_CLEAR,
	UMS_ACT_END
} UMS_AC_E;
typedef enum
{
	VAL_TYPE_VOID=0,
	VAL_TYPE_INT,
	VAL_TYPE_STR,
	VAL_TYPE_FLOAT,
	VAL_TYPE_DOUBLE,
}VAl_TYPE_E;
typedef struct
{
	VAl_TYPE_E valtype;
	char keystr[32];
	char* valstr;
}KEY_VAL_S;
#define KEYVAL_MAX	16
typedef struct
{
	int act;
	int keysum;
	char section[32];
	KEY_VAL_S keyval[KEYVAL_MAX];
}UMS_CMD_S;

#include <QObject>
typedef struct
{
    QString username;
    QString registration_time;
    QString last_online_time;
    int battery_lvl;
    int download_lvl;
}DB_DEV_INFO;

typedef struct
{
    QString dev_serial_number;
    QString record_time;
    QString download_time;
    QString local_url;
    QString size;
}DB_FILE_INFO;


#define IN
#define OUT

