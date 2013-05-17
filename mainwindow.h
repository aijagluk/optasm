/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include <QtWidgets/QMainWindow>
#include <QtGui>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QStackedLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMessageBox>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QLineEdit>
#include <QDockWidget>
#include "source_code.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QLCDNumber* m_plcdNumberOfLine;
    QPushButton* m_pcmdLineUp;
    QPushButton* m_pcmdLineDown;

    QPushButton* m_pcmdAddData;
    QPushButton* m_pcmdAddLabel;
    QPushButton* m_pcmdAddOpcode;
    QPushButton* m_pcmdAddDirective;
    QPushButton* m_pcmdAddComment;
    QPushButton* m_pcmdQuit;

    QPushButton* m_pcmdAddString;
    QPushButton* m_pcmdCancel;

    QPushButton* m_pcmdSaveFile;
    QPushButton* m_pcmdOpenFile;

    //Optimizing panel
    QPushButton* m_pcmdOptimize;
    QSpinBox* m_pspinMemory;

    //Label's buttons
    QPushButton* m_pcmdLabelGlobal;
    QPushButton* m_pcmdLabelLocal;
    QPushButton* m_pcmdLabelUnnamed;

    //Data's buttons
    QPushButton* m_pcmdDataSingle;
    QPushButton* m_pcmdDataDup;

    //Opcode's buttons
    //high lavel
    QPushButton* m_pcmdMoveDataCommands;
    QPushButton* m_pcmdSendFlagsCommands;
    QPushButton* m_pcmdStackCommands;
    QPushButton* m_pcmdIOCommands;
    QPushButton* m_pcmdAddingCommands;
    QPushButton* m_pcmdSubtractCommands;
    QPushButton* m_pcmdMulDivCommands;
    QPushButton* m_pcmdSingleOpArithmCommands;
    QPushButton* m_pcmdTransformCommands;
    QPushButton* m_pcmdDecCorrectionCommands;
    QPushButton* m_pcmdSymbolCorrectionCommands;
    QPushButton* m_pcmdLogicCommands;
    QPushButton* m_pcmdShiftCommands;
    QPushButton* m_pcmdBitCommands;
    QPushButton* m_pcmdUncondJumpCommands;
    QPushButton* m_pcmdCondJumpCommands;
    QPushButton* m_pcmdCycleManageCommands;
    QPushButton* m_pcmdInterruptCommands;
    QPushButton* m_pcmdFlagsCommands;
    QPushButton* m_pcmdSpecialCommands;
    QPushButton* m_pcmdPrefixCommmands;
    //  --move data
    QPushButton* m_pcmdOpcodeMOV;
    QPushButton* m_pcmdOpcodeXCHG;
    QPushButton* m_pcmdOpcodeXLAT;
    QPushButton* m_pcmdOpcodeLEA;
    QPushButton* m_pcmdOpcodeLDS;
    QPushButton* m_pcmdOpcodeLES;
    //  --send flags
    QPushButton* m_pcmdOpcodeLAHF;
    QPushButton* m_pcmdOpcodeSAHF;
    //  --stack
    QPushButton* m_pcmdOpcodePUSH;
    QPushButton* m_pcmdOpcodePOP;
    QPushButton* m_pcmdOpcodePUSHF;
    QPushButton* m_pcmdOpcodePOPF;
    //  --io
    QPushButton* m_pcmdOpcodeIN;
    QPushButton* m_pcmdOpcodeOUT;
    //  --adding
    QPushButton* m_pcmdOpcodeADD;
    QPushButton* m_pcmdOpcodeADC;
    //  --subtract
    QPushButton* m_pcmdOpcodeSUB;
    QPushButton* m_pcmdOpcodeSBB;
    QPushButton* m_pcmdOpcodeCMP;
    //  --mul/div
    QPushButton* m_pcmdOpcodeMUL;
    QPushButton* m_pcmdOpcodeIMUL;
    QPushButton* m_pcmdOpcodeDIV;
    QPushButton* m_pcmdOpcodeIDIV;
    //  --single operand arithmetic
    QPushButton* m_pcmdOpcodeINC;
    QPushButton* m_pcmdOpcodeDEC;
    QPushButton* m_pcmdOpcodeNEG;
    //  --transformation
    QPushButton* m_pcmdOpcodeCBW;
    QPushButton* m_pcmdOpcodeCWD;
    //  --dec correction
    QPushButton* m_pcmdOpcodeDAA;
    QPushButton* m_pcmdOpcodeDAS;
    //  --symbol correction
    QPushButton* m_pcmdOpcodeAAA;
    QPushButton* m_pcmdOpcodeAAS;
    QPushButton* m_pcmdOpcodeAAM;
    QPushButton* m_pcmdOpcodeAAD;
    //  --logic
    QPushButton* m_pcmdOpcodeAND;
    QPushButton* m_pcmdOpcodeOR;
    QPushButton* m_pcmdOpcodeXOR;
    QPushButton* m_pcmdOpcodeNOT;
    QPushButton* m_pcmdOpcodeTEST;
    //  --shift
    QPushButton* m_pcmdOpcodeRCL;
    QPushButton* m_pcmdOpcodeRCR;
    QPushButton* m_pcmdOpcodeROL;
    QPushButton* m_pcmdOpcodeROR;
    QPushButton* m_pcmdOpcodeSAL;
    QPushButton* m_pcmdOpcodeSAR;
    QPushButton* m_pcmdOpcodeSHL;
    QPushButton* m_pcmdOpcodeSHR;
    //  --bits
    QPushButton* m_pcmdOpcodeBT;
    QPushButton* m_pcmdOpcodeBTC;
    QPushButton* m_pcmdOpcodeBTR;
    QPushButton* m_pcmdOpcodeBTS;
    //  --uncond jumps
    QPushButton* m_pcmdOpcodeJMP;
    QPushButton* m_pcmdOpcodeCALL;
    QPushButton* m_pcmdOpcodeRET;
    //  --cond jumps
    QPushButton* m_pcmdOpcodeJL;
    QPushButton* m_pcmdOpcodeJNGE;
    QPushButton* m_pcmdOpcodeJNL;
    QPushButton* m_pcmdOpcodeJGE;
    QPushButton* m_pcmdOpcodeJLE;
    QPushButton* m_pcmdOpcodeJNG;
    QPushButton* m_pcmdOpcodeJNLE;
    QPushButton* m_pcmdOpcodeJG;
    QPushButton* m_pcmdOpcodeJB;
    QPushButton* m_pcmdOpcodeJNAE;
    QPushButton* m_pcmdOpcodeJC;
    QPushButton* m_pcmdOpcodeJBE;
    QPushButton* m_pcmdOpcodeJNA;
    QPushButton* m_pcmdOpcodeJNB;
    QPushButton* m_pcmdOpcodeJAE;
    QPushButton* m_pcmdOpcodeJNC;
    QPushButton* m_pcmdOpcodeJNBE;
    QPushButton* m_pcmdOpcodeJA;
    QPushButton* m_pcmdOpcodeJE;
    QPushButton* m_pcmdOpcodeJZ;
    QPushButton* m_pcmdOpcodeJP;
    QPushButton* m_pcmdOpcodeJPE;
    QPushButton* m_pcmdOpcodeJO;
    QPushButton* m_pcmdOpcodeJS;
    QPushButton* m_pcmdOpcodeJNE;
    QPushButton* m_pcmdOpcodeJNZ;
    QPushButton* m_pcmdOpcodeJNP;
    QPushButton* m_pcmdOpcodeJPO;
    QPushButton* m_pcmdOpcodeJNO;
    QPushButton* m_pcmdOpcodeJNS;
    QPushButton* m_pcmdOpcodeJCXZ;
    //  --cycle manage
    QPushButton* m_pcmdOpcodeLOOP;
    QPushButton* m_pcmdOpcodeLOOPE;
    QPushButton* m_pcmdOpcodeLOOPZ;
    QPushButton* m_pcmdOpcodeLOOPNE;
    QPushButton* m_pcmdOpcodeLOOPNZ;
    //  --interrupts
    QPushButton* m_pcmdOpcodeINT;
    QPushButton* m_pcmdOpcodeINTO;
    //  --flags
    QPushButton* m_pcmdOpcodeCLC;
    QPushButton* m_pcmdOpcodeSTC;
    QPushButton* m_pcmdOpcodeCMC;
    QPushButton* m_pcmdOpcodeCLD;
    QPushButton* m_pcmdOpcodeSTD;
    QPushButton* m_pcmdOpcodeCLI;
    QPushButton* m_pcmdOpcodeSTI;
    //  --special
    QPushButton* m_pcmdOpcodeHLT;
    QPushButton* m_pcmdOpcodeWAIT;
    QPushButton* m_pcmdOpcodeLOCK;
    QPushButton* m_pcmdOpcodeESC;
    QPushButton* m_pcmdOpcodeNOP;
    //  --prefixes
    QPushButton* m_pcmdOpcodeRepMovs;
    QPushButton* m_pcmdOpcodeRepStos;
    QPushButton* m_pcmdOpcodeRepeCmps;
    QPushButton* m_pcmdOpcodeRepeScas;
    QPushButton* m_pcmdOpcodeRepzCmps;
    QPushButton* m_pcmdOpcodeRepzScas;
    QPushButton* m_pcmdOpcodeRepneMovs;
    QPushButton* m_pcmdOpcodeRepneStos;
    QPushButton* m_pcmdOpcodeRepnzCmps;
    QPushButton* m_pcmdOpcodeRepnzScas;


    QTextEdit* m_pteSource;
    QVBoxLayout* m_pvblCentral;
    QGroupBox* m_pgbContent;
    QStackedLayout* m_pslContent;

    SourceStringType m_currentSSType;

    //Base objects
    GLabelGlobal* m_plabelGlobal;
    GLabelLocal* m_plabelLocal;
    GLabelUnnamed* m_plabelUnnamed;
    GData* m_pdata;
    GDataDup* m_pdataDup;
    GComment* m_pcomment;
    GOpcodeMOV* m_popcodeMOV;
    GOpcodeXCHG* m_popcodeXCHG;
    GOpcodeXLAT* m_popcodeXLAT;
    GOpcodeLEA* m_popcodeLEA;
    GOpcodeLDS* m_popcodeLDS;
    GOpcodeLES* m_popcodeLES;
    GOpcodeLAHF* m_popcodeLAHF;
    GOpcodeSAHF* m_popcodeSAHF;
    GOpcodePUSH* m_popcodePUSH;
    GOpcodePOP* m_popcodePOP;
    GOpcodePUSHF* m_popcodePUSHF;
    GOpcodePOPF* m_popcodePOPF;
    GOpcodeIN* m_popcodeIN;
    GOpcodeOUT* m_popcodeOUT;
    GOpcodeADD* m_popcodeADD;
    GOpcodeADC* m_popcodeADC;
    GOpcodeSUB* m_popcodeSUB;
    GOpcodeSBB* m_popcodeSBB;
    GOpcodeCMP* m_popcodeCMP;
    GOpcodeMUL* m_popcodeMUL;
    GOpcodeIMUL* m_popcodeIMUL;
    GOpcodeDIV* m_popcodeDIV;
    GOpcodeIDIV* m_popcodeIDIV;
    GOpcodeINC* m_popcodeINC;
    GOpcodeDEC* m_popcodeDEC;
    GOpcodeNEG* m_popcodeNEG;
    GOpcodeCBW* m_popcodeCBW;
    GOpcodeCWD* m_popcodeCWD;
    GOpcodeDAA* m_popcodeDAA;
    GOpcodeDAS* m_popcodeDAS;
    GOpcodeAAA* m_popcodeAAA;
    GOpcodeAAS* m_popcodeAAS;
    GOpcodeAAM* m_popcodeAAM;
    GOpcodeAAD* m_popcodeAAD;
    GOpcodeAND* m_popcodeAND;
    GOpcodeOR* m_popcodeOR;
    GOpcodeXOR* m_popcodeXOR;
    GOpcodeNOT* m_popcodeNOT;
    GOpcodeTEST* m_popcodeTEST;
    GOpcodeRCL* m_popcodeRCL;
    GOpcodeRCR* m_popcodeRCR;
    GOpcodeROL* m_popcodeROL;
    GOpcodeROR* m_popcodeROR;
    GOpcodeSAL* m_popcodeSAL;
    GOpcodeSAR* m_popcodeSAR;
    GOpcodeSHL* m_popcodeSHL;
    GOpcodeSHR* m_popcodeSHR;
    GOpcodeBT* m_popcodeBT;
    GOpcodeBTC* m_popcodeBTC;
    GOpcodeBTR* m_popcodeBTR;
    GOpcodeBTS* m_popcodeBTS;
    GOpcodeJMP* m_popcodeJMP;
    GOpcodeCALL* m_popcodeCALL;
    GOpcodeRET* m_popcodeRET;
    GOpcodeJL* m_popcodeJL;
    GOpcodeJNGE* m_popcodeJNGE;
    GOpcodeJNL* m_popcodeJNL;
    GOpcodeJGE* m_popcodeJGE;
    GOpcodeJLE* m_popcodeJLE;
    GOpcodeJNG* m_popcodeJNG;
    GOpcodeJNLE* m_popcodeJNLE;
    GOpcodeJG* m_popcodeJG;
    GOpcodeJB* m_popcodeJB;
    GOpcodeJNAE* m_popcodeJNAE;
    GOpcodeJC* m_popcodeJC;
    GOpcodeJBE* m_popcodeJBE;
    GOpcodeJNA* m_popcodeJNA;
    GOpcodeJNB* m_popcodeJNB;
    GOpcodeJAE* m_popcodeJAE;
    GOpcodeJNC* m_popcodeJNC;
    GOpcodeJNBE* m_popcodeJNBE;
    GOpcodeJA* m_popcodeJA;
    GOpcodeJE* m_popcodeJE;
    GOpcodeJZ* m_popcodeJZ;
    GOpcodeJP* m_popcodeJP;
    GOpcodeJPE* m_popcodeJPE;
    GOpcodeJO* m_popcodeJO;
    GOpcodeJS* m_popcodeJS;
    GOpcodeJNE* m_popcodeJNE;
    GOpcodeJNZ* m_popcodeJNZ;
    GOpcodeJNP* m_popcodeJNP;
    GOpcodeJPO* m_popcodeJPO;
    GOpcodeJNO* m_popcodeJNO;
    GOpcodeJNS* m_popcodeJNS;
    GOpcodeJCXZ* m_popcodeJCXZ;
    GOpcodeLOOP* m_popcodeLOOP;
    GOpcodeLOOPE* m_popcodeLOOPE;
    GOpcodeLOOPZ* m_popcodeLOOPZ;
    GOpcodeLOOPNE* m_popcodeLOOPNE;
    GOpcodeLOOPNZ* m_popcodeLOOPNZ;
    GOpcodeINT* m_popcodeINT;
    GOpcodeINTO* m_popcodeINTO;
    GOpcodeCLC* m_popcodeCLC;
    GOpcodeSTC* m_popcodeSTC;
    GOpcodeCMC* m_popcodeCMC;
    GOpcodeCLD* m_popcodeCLD;
    GOpcodeSTD* m_popcodeSTD;
    GOpcodeCLI* m_popcodeCLI;
    GOpcodeSTI* m_popcodeSTI;
    GOpcodeHLT* m_popcodeHLT;
    GOpcodeWAIT* m_popcodeWAIT;
    GOpcodeLOCK* m_popcodeLOCK;
    GOpcodeESC* m_popcodeESC;
    GOpcodeNOP* m_popcodeNOP;
//    GOpcodeREP_MOVS* m_popcodeRepMovs;
//    GOpcodeREP_STOS* m_popcodeRepStos;
//    GOpcodeREPE_CMPS* m_popcodeRepeCmps;
//    GOpcodeREPE_SCAS* m_popcodeRepeScas;
//    GOpcodeREPZ_CMPS* m_popcodeRepzCmps;
//    GOpcodeREPZ_SCAS* m_popcodeRepzScas;
//    GOpcodeREPNE_MOVS* m_popcodeRepneMovs;
//    GOpcodeREPNE_STOS* m_popcodeRepneStos;
//    GOpcodeREPNZ_CMPS* m_popcodeRepnzCmps;
//    GOpcodeREPNZ_SCAS* m_popcodeRepnzScas;

    GSourceCode* m_ptheCode;

private:
    Ui::MainWindow *ui;
    void loadAllPanels(void);
    int m_nNumberOfLine;

    void insertNOP(int line);
    void insertNOPs(int line, int count);
    void insertNopBeforeCycle(int begin);
    void insertNopToCycle(int end);

public slots:
    void makeLabelGlobal(void);
    void makeLabelLocal(void);
    void makeLabelUnnamed(void);
    void makeDataSingle(void);
    void makeDataDup(void);
    void makeComment(void);
    void makeOpcodeMOV(void);
    void makeOpcodeXCHG(void);
    void makeOpcodeXLAT(void);
    void makeOpcodeLEA(void);
    void makeOpcodeLDS(void);
    void makeOpcodeLES(void);
    void makeOpcodeLAHF(void);
    void makeOpcodeSAHF(void);
    void makeOpcodePUSH(void);
    void makeOpcodePOP(void);
    void makeOpcodePUSHF(void);
    void makeOpcodePOPF(void);
    void makeOpcodeIN(void);
    void makeOpcodeOUT(void);
    void makeOpcodeADD(void);
    void makeOpcodeADC(void);
    void makeOpcodeSUB(void);
    void makeOpcodeSBB(void);
    void makeOpcodeCMP(void);
    void makeOpcodeMUL(void);
    void makeOpcodeIMUL(void);
    void makeOpcodeDIV(void);
    void makeOpcodeIDIV(void);
    void makeOpcodeINC(void);
    void makeOpcodeDEC(void);
    void makeOpcodeNEG(void);
    void makeOpcodeCBW(void);
    void makeOpcodeCWD(void);
    void makeOpcodeDAA(void);
    void makeOpcodeDAS(void);
    void makeOpcodeAAA(void);
    void makeOpcodeAAS(void);
    void makeOpcodeAAM(void);
    void makeOpcodeAAD(void);
    void makeOpcodeAND(void);
    void makeOpcodeOR(void);
    void makeOpcodeXOR(void);
    void makeOpcodeNOT(void);
    void makeOpcodeTEST(void);
    void makeOpcodeRCL(void);
    void makeOpcodeRCR(void);
    void makeOpcodeROL(void);
    void makeOpcodeROR(void);
    void makeOpcodeSAL(void);
    void makeOpcodeSAR(void);
    void makeOpcodeSHL(void);
    void makeOpcodeSHR(void);
    void makeOpcodeBT(void);
    void makeOpcodeBTC(void);
    void makeOpcodeBTR(void);
    void makeOpcodeBTS(void);
    void makeOpcodeJMP(void);
    void makeOpcodeCALL(void);
    void makeOpcodeRET(void);
    void makeOpcodeJL(void);
    void makeOpcodeJNGE(void);
    void makeOpcodeJNL(void);
    void makeOpcodeJGE(void);
    void makeOpcodeJLE(void);
    void makeOpcodeJNG(void);
    void makeOpcodeJNLE(void);
    void makeOpcodeJG(void);
    void makeOpcodeJB(void);
    void makeOpcodeJNAE(void);
    void makeOpcodeJC(void);
    void makeOpcodeJBE(void);
    void makeOpcodeJNA(void);
    void makeOpcodeJNB(void);
    void makeOpcodeJAE(void);
    void makeOpcodeJNC(void);
    void makeOpcodeJNBE(void);
    void makeOpcodeJA(void);
    void makeOpcodeJE(void);
    void makeOpcodeJZ(void);
    void makeOpcodeJP(void);
    void makeOpcodeJPE(void);
    void makeOpcodeJO(void);
    void makeOpcodeJS(void);
    void makeOpcodeJNE(void);
    void makeOpcodeJNZ(void);
    void makeOpcodeJNP(void);
    void makeOpcodeJPO(void);
    void makeOpcodeJNO(void);
    void makeOpcodeJNS(void);
    void makeOpcodeJCXZ(void);
    void makeOpcodeLOOP(void);
    void makeOpcodeLOOPE(void);
    void makeOpcodeLOOPZ(void);
    void makeOpcodeLOOPNE(void);
    void makeOpcodeLOOPNZ(void);
    void makeOpcodeINT(void);
    void makeOpcodeINTO(void);
    void makeOpcodeCLC(void);
    void makeOpcodeSTC(void);
    void makeOpcodeCMC(void);
    void makeOpcodeCLD(void);
    void makeOpcodeSTD(void);
    void makeOpcodeCLI(void);
    void makeOpcodeSTI(void);
    void makeOpcodeHLT(void);
    void makeOpcodeWAIT(void);
    void makeOpcodeLOCK(void);
    void makeOpcodeESC(void);
    void makeOpcodeNOP(void);
//    void makeOpcodeRepMovs(void);
//    void makeOpcodeRepStos(void);
//    void makeOpcodeRepeCmps(void);
//    void makeOpcodeRepeScas(void);
//    void makeOpcodeRepzCmps(void);
//    void makeOpcodeRepzScas(void);
//    void makeOpcodeRepneMovs(void);
//    void makeOpcodeRepneStos(void);
//    void makeOpcodeRepnzCmps(void);
//    void makeOpcodeRepnzScas(void);
    void lineUp(void);
    void lineDown(void);
    void lineAdd(void);
    void lineCancel(void);    
    void saveFile(void);
    void openFile(void);
    void exitApp(void);    

    void doOptimize(void);
};

#endif // MAINWINDOW_H
