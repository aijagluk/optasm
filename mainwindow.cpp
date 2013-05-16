/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    m_ptheCode = new GSourceCode();

    m_pcmdAddString = new QPushButton("Добавить");
    m_pcmdAddString->setDefault(true);
    m_pcmdCancel = new QPushButton("Отмена");
    m_pcmdAddString->setEnabled(false);
    m_pcmdCancel->setEnabled(false);
    QHBoxLayout* phblOkCancel = new QHBoxLayout();
    phblOkCancel->addWidget(m_pcmdAddString);
    phblOkCancel->addWidget(m_pcmdCancel);

    QVBoxLayout* pvblLeftPanel = new QVBoxLayout();
    //Datas
    m_pcmdAddData = new QPushButton("+ Данные");
    m_pcmdDataSingle = new QPushButton("Single");
    m_pcmdDataDup = new QPushButton("Dup");
    m_pcmdDataSingle->setToolTip("Single data");
    m_pcmdDataDup->setToolTip("Dup data");
    QVBoxLayout* pvblDatasMenu = new QVBoxLayout();
    pvblDatasMenu->setSpacing(0);
    pvblDatasMenu->addWidget(m_pcmdDataSingle);
    pvblDatasMenu->addWidget(m_pcmdDataDup);
    QMenu* pmenuDatas = new QMenu(m_pcmdAddData);
    pmenuDatas->setLayout(pvblDatasMenu);
    m_pcmdAddData->setMenu(pmenuDatas);
    m_pcmdAddData->setToolTip("Добавить данные");

    //Labels
    m_pcmdAddLabel = new QPushButton("+ Метка");
    m_pcmdLabelGlobal = new QPushButton("Глобальная");
    m_pcmdLabelLocal = new QPushButton("Локальная");
    m_pcmdLabelUnnamed = new QPushButton("Безымянная");
    m_pcmdLabelGlobal->setToolTip("Добавить глобальную метку");
    m_pcmdLabelLocal->setToolTip("Добавить локальную метку");
    m_pcmdLabelUnnamed->setToolTip("Добавить безымянную метку");
    QVBoxLayout* pvblLabelsMenu = new QVBoxLayout();
    pvblLabelsMenu->setSpacing(0);
    pvblLabelsMenu->addWidget(m_pcmdLabelGlobal);
    pvblLabelsMenu->addWidget(m_pcmdLabelLocal);
    pvblLabelsMenu->addWidget(m_pcmdLabelUnnamed);
    QMenu* pmenuLabels = new QMenu(m_pcmdAddLabel);
    pmenuLabels->setLayout(pvblLabelsMenu);
    m_pcmdAddLabel->setMenu(pmenuLabels);
    m_pcmdAddLabel->setToolTip("Добавить метку");

    m_pcmdAddDirective = new QPushButton("+ Директива");

    //Opcodes
    m_pcmdAddOpcode = new QPushButton("+ Опкод");
    //  --- high level
    m_pcmdMoveDataCommands = new QPushButton("Передача данных");
    m_pcmdSendFlagsCommands = new QPushButton("Пересылка флагов");
    m_pcmdStackCommands = new QPushButton("Стековые команды");
    m_pcmdIOCommands = new QPushButton("Ввод/вывод");
    m_pcmdAddingCommands = new QPushButton("Сложение");
    m_pcmdSubtractCommands = new QPushButton("Вычитание");
    m_pcmdMulDivCommands = new QPushButton("Умножение/Деление");
    m_pcmdSingleOpArithmCommands = new QPushButton("Арифметика с одним операндом");
    m_pcmdTransformCommands = new QPushButton("Преобразования");
    m_pcmdDecCorrectionCommands = new QPushButton("Десятичная коррекция");
    m_pcmdSymbolCorrectionCommands = new QPushButton("Символьная коррекция");
    m_pcmdLogicCommands = new QPushButton("Логические команды");
    m_pcmdShiftCommands = new QPushButton("Сдвиги");
    m_pcmdBitCommands = new QPushButton("Работа с битами");
    m_pcmdUncondJumpCommands = new QPushButton("Безусловные переходы");
    m_pcmdCondJumpCommands = new QPushButton("Условные переходы");
    m_pcmdCycleManageCommands = new QPushButton("Управление циклом");
    m_pcmdInterruptCommands = new QPushButton("Прерывания");
    m_pcmdFlagsCommands = new QPushButton("Установка флажков");
    m_pcmdSpecialCommands = new QPushButton("Специальные");
    m_pcmdPrefixCommmands = new QPushButton("Префиксы REPx");


    QVBoxLayout* pvblOpcodesCategories = new QVBoxLayout();
    pvblOpcodesCategories->setSpacing(0);
    pvblOpcodesCategories->addWidget(m_pcmdMoveDataCommands);
    pvblOpcodesCategories->addWidget(m_pcmdSendFlagsCommands);
    pvblOpcodesCategories->addWidget(m_pcmdStackCommands);
    pvblOpcodesCategories->addWidget(m_pcmdIOCommands);
    pvblOpcodesCategories->addWidget(m_pcmdAddingCommands);
    pvblOpcodesCategories->addWidget(m_pcmdSubtractCommands);
    pvblOpcodesCategories->addWidget(m_pcmdMulDivCommands);
    pvblOpcodesCategories->addWidget(m_pcmdSingleOpArithmCommands);
    pvblOpcodesCategories->addWidget(m_pcmdTransformCommands);
    pvblOpcodesCategories->addWidget(m_pcmdDecCorrectionCommands);
    pvblOpcodesCategories->addWidget(m_pcmdSymbolCorrectionCommands);
//    pvblOpcodesCategories->addWidget(m_pcmdPrefixCommmands);
    pvblOpcodesCategories->addWidget(m_pcmdLogicCommands);
    pvblOpcodesCategories->addWidget(m_pcmdShiftCommands);
    pvblOpcodesCategories->addWidget(m_pcmdBitCommands);
    pvblOpcodesCategories->addWidget(m_pcmdUncondJumpCommands);
    pvblOpcodesCategories->addWidget(m_pcmdCondJumpCommands);
    pvblOpcodesCategories->addWidget(m_pcmdCycleManageCommands);
    pvblOpcodesCategories->addWidget(m_pcmdInterruptCommands);
    pvblOpcodesCategories->addWidget(m_pcmdFlagsCommands);
    pvblOpcodesCategories->addWidget(m_pcmdSpecialCommands);

    QMenu* pmenuOpcodes = new QMenu(m_pcmdAddOpcode);
    pmenuOpcodes->setLayout(pvblOpcodesCategories);
    m_pcmdAddOpcode->setMenu(pmenuOpcodes);
    m_pcmdAddOpcode->setToolTip("Добавить опкод");

    //  --- Передача данных
    m_pcmdOpcodeMOV = new QPushButton("mov");
    m_pcmdOpcodeMOV->setToolTip("Добавить mov");
    m_pcmdOpcodeXCHG = new QPushButton("xchg");
    m_pcmdOpcodeXCHG->setToolTip("Добавить xchg");
    m_pcmdOpcodeXLAT = new QPushButton("xlat");
    m_pcmdOpcodeXLAT->setToolTip("Добавить xlat");
    m_pcmdOpcodeLEA = new QPushButton("lea");
    m_pcmdOpcodeLEA->setToolTip("Добавить lea");
    m_pcmdOpcodeLDS = new QPushButton("lds");
    m_pcmdOpcodeLDS->setToolTip("Добавить lds");
    m_pcmdOpcodeLES = new QPushButton("les");
    m_pcmdOpcodeLES->setToolTip("Добавить les");

    QGridLayout* pgridMoveDataCommands = new QGridLayout();
    pgridMoveDataCommands->setSpacing(0);
    pgridMoveDataCommands->addWidget(m_pcmdOpcodeMOV, 0, 0);  //опкоды
    pgridMoveDataCommands->addWidget(m_pcmdOpcodeXCHG, 1, 0);
    pgridMoveDataCommands->addWidget(m_pcmdOpcodeXLAT, 2, 0);
    pgridMoveDataCommands->addWidget(m_pcmdOpcodeLEA, 0, 1);
    pgridMoveDataCommands->addWidget(m_pcmdOpcodeLDS, 1, 1);
    pgridMoveDataCommands->addWidget(m_pcmdOpcodeLES, 2, 1);

    QMenu* pmenuMoveDataCommands = new QMenu(m_pcmdMoveDataCommands);
    pmenuMoveDataCommands->setLayout(pgridMoveDataCommands);
    m_pcmdMoveDataCommands->setMenu(pmenuMoveDataCommands);

    //  --- пересылка флагов
    m_pcmdOpcodeLAHF = new QPushButton("lahf");
    m_pcmdOpcodeLAHF->setToolTip("Добавить lahf");
    m_pcmdOpcodeSAHF = new QPushButton("sahf");
    m_pcmdOpcodeSAHF->setToolTip("Добавить sahf");

    QVBoxLayout* pvblSendFlagsCommands = new QVBoxLayout();
    pvblSendFlagsCommands->setSpacing(0);
    pvblSendFlagsCommands->addWidget(m_pcmdOpcodeLAHF);  //опкоды
    pvblSendFlagsCommands->addWidget(m_pcmdOpcodeSAHF);
    QMenu* pmenuSendFlagsCommands = new QMenu(m_pcmdSendFlagsCommands);
    pmenuSendFlagsCommands->setLayout(pvblSendFlagsCommands);
    m_pcmdSendFlagsCommands->setMenu(pmenuSendFlagsCommands);

    //  --- стековые команды
    m_pcmdOpcodePUSH = new QPushButton("push");
    m_pcmdOpcodePUSH->setToolTip("Добавить push");
    m_pcmdOpcodePOP = new QPushButton("pop");
    m_pcmdOpcodePOP->setToolTip("Добавить pop");
    m_pcmdOpcodePUSHF = new QPushButton("pushf");
    m_pcmdOpcodePUSHF->setToolTip("Добавить pushf");
    m_pcmdOpcodePOPF = new QPushButton("popf");
    m_pcmdOpcodePOPF->setToolTip("Добавить popf");

    QGridLayout* pgridStackCommands = new QGridLayout();
    pgridStackCommands->setSpacing(0);
    pgridStackCommands->addWidget(m_pcmdOpcodePUSH, 0, 0);  //опкоды
    pgridStackCommands->addWidget(m_pcmdOpcodePOP, 1, 0);
    pgridStackCommands->addWidget(m_pcmdOpcodePUSHF, 0, 1);
    pgridStackCommands->addWidget(m_pcmdOpcodePOPF, 1, 1);
    QMenu* pmenuStackCommands = new QMenu(m_pcmdStackCommands);
    pmenuStackCommands->setLayout(pgridStackCommands);
    m_pcmdStackCommands->setMenu(pmenuStackCommands);

    //  --- ввод/вывод
    m_pcmdOpcodeIN = new QPushButton("in");
    m_pcmdOpcodeIN->setToolTip("Добавить in");
    m_pcmdOpcodeOUT = new QPushButton("out");
    m_pcmdOpcodeOUT->setToolTip("Добавить out");

    QVBoxLayout* pvblIOCommands = new QVBoxLayout();
    pvblIOCommands->setSpacing(0);
    pvblIOCommands->addWidget(m_pcmdOpcodeIN);  //опкоды
    pvblIOCommands->addWidget(m_pcmdOpcodeOUT);
    QMenu* pmenuIOCommands = new QMenu(m_pcmdIOCommands);
    pmenuIOCommands->setLayout(pvblIOCommands);
    m_pcmdIOCommands->setMenu(pmenuIOCommands);

    //  --- сложение
    m_pcmdOpcodeADD = new QPushButton("add");
    m_pcmdOpcodeADD->setToolTip("Добавить add");
    m_pcmdOpcodeADC = new QPushButton("adc");
    m_pcmdOpcodeADC->setToolTip("Добавить adc");

    QVBoxLayout* pvblAddingCommands = new QVBoxLayout();
    pvblAddingCommands->setSpacing(0);
    pvblAddingCommands->addWidget(m_pcmdOpcodeADD);  //опкоды
    pvblAddingCommands->addWidget(m_pcmdOpcodeADC);
    QMenu* pmenuAddingCommands = new QMenu(m_pcmdAddingCommands);
    pmenuAddingCommands->setLayout(pvblAddingCommands);
    m_pcmdAddingCommands->setMenu(pmenuAddingCommands);

    //  --  вычитание
    m_pcmdOpcodeSUB = new QPushButton("sub");
    m_pcmdOpcodeSUB->setToolTip("Добавить sub");
    m_pcmdOpcodeSBB = new QPushButton("sbb");
    m_pcmdOpcodeSBB->setToolTip("Добавить sbb");
    m_pcmdOpcodeCMP = new QPushButton("cmp");
    m_pcmdOpcodeCMP->setToolTip("Добавить cmp");

    QVBoxLayout* pvblSubtractCommands = new QVBoxLayout();
    pvblSubtractCommands->setSpacing(0);
    pvblSubtractCommands->addWidget(m_pcmdOpcodeSUB);  //опкоды
    pvblSubtractCommands->addWidget(m_pcmdOpcodeSBB);
    pvblSubtractCommands->addWidget(m_pcmdOpcodeCMP);
    QMenu* pmenuSubtractCommands = new QMenu(m_pcmdSubtractCommands);
    pmenuSubtractCommands->setLayout(pvblSubtractCommands);
    m_pcmdSubtractCommands->setMenu(pmenuSubtractCommands);

    //  --  умножение / деление
    m_pcmdOpcodeMUL = new QPushButton("mul");
    m_pcmdOpcodeMUL->setToolTip("Добавить mul");
    m_pcmdOpcodeIMUL = new QPushButton("imul");
    m_pcmdOpcodeIMUL->setToolTip("Добавить imul");
    m_pcmdOpcodeDIV = new QPushButton("div");
    m_pcmdOpcodeDIV->setToolTip("Добавить div");
    m_pcmdOpcodeIDIV = new QPushButton("idiv");
    m_pcmdOpcodeIDIV->setToolTip("Добавить idiv");

    QGridLayout* pgridMulDivCommands = new QGridLayout();
    pgridMulDivCommands->setSpacing(0);
    pgridMulDivCommands->addWidget(m_pcmdOpcodeMUL, 0, 0);  //опкоды
    pgridMulDivCommands->addWidget(m_pcmdOpcodeIMUL, 1, 0);
    pgridMulDivCommands->addWidget(m_pcmdOpcodeDIV, 0, 1);
    pgridMulDivCommands->addWidget(m_pcmdOpcodeIDIV, 1, 1);
    QMenu* pmenuMulDivCommands = new QMenu(m_pcmdMulDivCommands);
    pmenuMulDivCommands->setLayout(pgridMulDivCommands);
    m_pcmdMulDivCommands->setMenu(pmenuMulDivCommands);

    //  --  арифметика с одним операндом
    m_pcmdOpcodeINC = new QPushButton("inc");
    m_pcmdOpcodeINC->setToolTip("Добавить inc");
    m_pcmdOpcodeDEC = new QPushButton("dec");
    m_pcmdOpcodeDEC->setToolTip("Добавить dec");
    m_pcmdOpcodeNEG = new QPushButton("neg");
    m_pcmdOpcodeNEG->setToolTip("Добавить neg");

    QVBoxLayout* pvblSingleOpArithmCommands = new QVBoxLayout();
    pvblSingleOpArithmCommands->setSpacing(0);
    pvblSingleOpArithmCommands->addWidget(m_pcmdOpcodeINC);  //опкоды
    pvblSingleOpArithmCommands->addWidget(m_pcmdOpcodeDEC);
    pvblSingleOpArithmCommands->addWidget(m_pcmdOpcodeNEG);
    QMenu* pmenuSingleOpArithmCommands = new QMenu(m_pcmdSingleOpArithmCommands);
    pmenuSingleOpArithmCommands->setLayout(pvblSingleOpArithmCommands);
    m_pcmdSingleOpArithmCommands->setMenu(pmenuSingleOpArithmCommands);

    //  --  преобразования
    m_pcmdOpcodeCBW = new QPushButton("cbw");
    m_pcmdOpcodeCBW->setToolTip("Добавить cbw");
    m_pcmdOpcodeCWD = new QPushButton("cwd");
    m_pcmdOpcodeCWD->setToolTip("Добавить cwd");

    QVBoxLayout* pvblTransformCommands = new QVBoxLayout();
    pvblTransformCommands->setSpacing(0);
    pvblTransformCommands->addWidget(m_pcmdOpcodeCBW);  //опкоды
    pvblTransformCommands->addWidget(m_pcmdOpcodeCWD);
    QMenu* pmenuTransformCommands = new QMenu(m_pcmdTransformCommands);
    pmenuTransformCommands->setLayout(pvblTransformCommands);
    m_pcmdTransformCommands->setMenu(pmenuTransformCommands);

    //  --  десятичная коррекция
    m_pcmdOpcodeDAA = new QPushButton("daa");
    m_pcmdOpcodeDAA->setToolTip("Добавить daa");
    m_pcmdOpcodeDAS = new QPushButton("das");
    m_pcmdOpcodeDAS->setToolTip("Добавить das");

    QVBoxLayout* pvblDecCorrectionCommands = new QVBoxLayout();
    pvblDecCorrectionCommands->setSpacing(0);
    pvblDecCorrectionCommands->addWidget(m_pcmdOpcodeDAA);  //опкоды
    pvblDecCorrectionCommands->addWidget(m_pcmdOpcodeDAS);
    QMenu* pmenuDecCorrection = new QMenu(m_pcmdDecCorrectionCommands);
    pmenuDecCorrection->setLayout(pvblDecCorrectionCommands);
    m_pcmdDecCorrectionCommands->setMenu(pmenuDecCorrection);

    //  --  символьная коррекция
    m_pcmdOpcodeAAA = new QPushButton("aaa");
    m_pcmdOpcodeAAA->setToolTip("Добавить aaa");
    m_pcmdOpcodeAAS = new QPushButton("aas");
    m_pcmdOpcodeAAS->setToolTip("Добавить aas");
    m_pcmdOpcodeAAM = new QPushButton("aam");
    m_pcmdOpcodeAAM->setToolTip("Добавить aam");
    m_pcmdOpcodeAAD = new QPushButton("aad");
    m_pcmdOpcodeAAD->setToolTip("Добавить aad");

    QGridLayout* pgridSymbolCorrectionCommands = new QGridLayout();
    pgridSymbolCorrectionCommands->setSpacing(0);
    pgridSymbolCorrectionCommands->addWidget(m_pcmdOpcodeAAA, 0, 0);  //опкоды
    pgridSymbolCorrectionCommands->addWidget(m_pcmdOpcodeAAS, 1, 0);
    pgridSymbolCorrectionCommands->addWidget(m_pcmdOpcodeAAM, 0, 1);
    pgridSymbolCorrectionCommands->addWidget(m_pcmdOpcodeAAD, 1, 1);
    QMenu* pmenuSymbolCorrectionCommands = new QMenu(m_pcmdSymbolCorrectionCommands);
    pmenuSymbolCorrectionCommands->setLayout(pgridSymbolCorrectionCommands);
    m_pcmdSymbolCorrectionCommands->setMenu(pmenuSymbolCorrectionCommands);

    //  --  логические
    m_pcmdOpcodeAND = new QPushButton("and");
    m_pcmdOpcodeAND->setToolTip("Добавить and");
    m_pcmdOpcodeOR = new QPushButton("or");
    m_pcmdOpcodeOR->setToolTip("Добавить or");
    m_pcmdOpcodeXOR = new QPushButton("xor");
    m_pcmdOpcodeXOR->setToolTip("Добавить xor");
    m_pcmdOpcodeTEST = new QPushButton("test");
    m_pcmdOpcodeTEST->setToolTip("Добавить test");
    m_pcmdOpcodeNOT = new QPushButton("not");
    m_pcmdOpcodeNOT->setToolTip("Добавить not");

    QGridLayout* pgridLogicCommands = new QGridLayout();
    pgridLogicCommands->setSpacing(0);
    pgridLogicCommands->addWidget(m_pcmdOpcodeAND, 0, 0);  //опкоды
    pgridLogicCommands->addWidget(m_pcmdOpcodeOR, 1, 0);
    pgridLogicCommands->addWidget(m_pcmdOpcodeTEST, 2, 0);
    pgridLogicCommands->addWidget(m_pcmdOpcodeXOR, 0, 1);
    pgridLogicCommands->addWidget(m_pcmdOpcodeNOT, 1, 1);
    QMenu* pmenuLogicCommands = new QMenu(m_pcmdLogicCommands);
    pmenuLogicCommands->setLayout(pgridLogicCommands);
    m_pcmdLogicCommands->setMenu(pmenuLogicCommands);

    //  --  сдвиги
    m_pcmdOpcodeRCL = new QPushButton("rcl");
    m_pcmdOpcodeRCL->setToolTip("Добавить rcl");
    m_pcmdOpcodeRCR = new QPushButton("rcr");
    m_pcmdOpcodeRCR->setToolTip("Добавить rcr");
    m_pcmdOpcodeROL = new QPushButton("rol");
    m_pcmdOpcodeROL->setToolTip("Добавить rol");
    m_pcmdOpcodeROR = new QPushButton("ror");
    m_pcmdOpcodeROR->setToolTip("Добавить ror");
    m_pcmdOpcodeSAL = new QPushButton("sal");
    m_pcmdOpcodeSAL->setToolTip("Добавить sal");
    m_pcmdOpcodeSAR = new QPushButton("sar");
    m_pcmdOpcodeSAR->setToolTip("Добавить sar");
    m_pcmdOpcodeSHL = new QPushButton("shl");
    m_pcmdOpcodeSHL->setToolTip("Добавить shl");
    m_pcmdOpcodeSHR = new QPushButton("shr");
    m_pcmdOpcodeSHR->setToolTip("Добавить shr");

    QGridLayout* pgridShiftCommands = new QGridLayout();
    pgridShiftCommands->setSpacing(0);
    pgridShiftCommands->addWidget(m_pcmdOpcodeRCL, 0, 0);  //  опкоды
    pgridShiftCommands->addWidget(m_pcmdOpcodeRCR, 1, 0);
    pgridShiftCommands->addWidget(m_pcmdOpcodeROL, 2, 0);
    pgridShiftCommands->addWidget(m_pcmdOpcodeROR, 3, 0);
    pgridShiftCommands->addWidget(m_pcmdOpcodeSAL, 0, 1);
    pgridShiftCommands->addWidget(m_pcmdOpcodeSAR, 1, 1);
    pgridShiftCommands->addWidget(m_pcmdOpcodeSHL, 2, 1);
    pgridShiftCommands->addWidget(m_pcmdOpcodeSHR, 3, 1);
    QMenu* pmenuShiftCommands = new QMenu(m_pcmdShiftCommands);
    pmenuShiftCommands->setLayout(pgridShiftCommands);
    m_pcmdShiftCommands->setMenu(pmenuShiftCommands);

    //  --  работа с битами
    m_pcmdOpcodeBT = new QPushButton("bt");
    m_pcmdOpcodeBT->setToolTip("Добавить bt");
    m_pcmdOpcodeBTC = new QPushButton("btc");
    m_pcmdOpcodeBTC->setToolTip("Добавить btc");
    m_pcmdOpcodeBTR = new QPushButton("btr");
    m_pcmdOpcodeBTR->setToolTip("Добавить btr");
    m_pcmdOpcodeBTS = new QPushButton("bts");
    m_pcmdOpcodeBTS->setToolTip("Добавить bts");

    QGridLayout* pgridBitCommands = new QGridLayout();
    pgridBitCommands->setSpacing(0);
    pgridBitCommands->addWidget(m_pcmdOpcodeBT, 0, 0);  //  опкоды
    pgridBitCommands->addWidget(m_pcmdOpcodeBTC, 1, 0);
    pgridBitCommands->addWidget(m_pcmdOpcodeBTR, 0, 1);
    pgridBitCommands->addWidget(m_pcmdOpcodeBTS, 1, 1);
    QMenu* pmenuBitCommands = new QMenu(m_pcmdBitCommands);
    pmenuBitCommands->setLayout(pgridBitCommands);
    m_pcmdBitCommands->setMenu(pmenuBitCommands);

    //  --  безусловные переходы
    m_pcmdOpcodeJMP = new QPushButton("jmp");
    m_pcmdOpcodeJMP->setToolTip("Добавить jmp");
    m_pcmdOpcodeCALL = new QPushButton("call");
    m_pcmdOpcodeCALL->setToolTip("Добавить call");
    m_pcmdOpcodeRET = new QPushButton("ret");
    m_pcmdOpcodeRET->setToolTip("Добавить ret");

    QVBoxLayout* pvblUncondJumpCommands = new QVBoxLayout();
    pvblUncondJumpCommands->setSpacing(0);
    pvblUncondJumpCommands->addWidget(m_pcmdOpcodeJMP); //  опкоды
    pvblUncondJumpCommands->addWidget(m_pcmdOpcodeCALL);
    pvblUncondJumpCommands->addWidget(m_pcmdOpcodeRET);
    QMenu* pmenuUncondJumpCommands = new QMenu(m_pcmdUncondJumpCommands);
    pmenuUncondJumpCommands->setLayout(pvblUncondJumpCommands);
    m_pcmdUncondJumpCommands->setMenu(pmenuUncondJumpCommands);

    //  --  условные переходы
    m_pcmdOpcodeJL = new QPushButton("jl");
    m_pcmdOpcodeJL->setToolTip("Добавить jl");
    m_pcmdOpcodeJNGE = new QPushButton("jnge");
    m_pcmdOpcodeJNGE->setToolTip("Добавить jnge");
    m_pcmdOpcodeJNL = new QPushButton("jnl");
    m_pcmdOpcodeJNL->setToolTip("Добавить jnl");
    m_pcmdOpcodeJGE = new QPushButton("jge");
    m_pcmdOpcodeJGE->setToolTip("Добавить jge");
    m_pcmdOpcodeJLE = new QPushButton("jle");
    m_pcmdOpcodeJLE->setToolTip("Добавить jle");
    m_pcmdOpcodeJNG = new QPushButton("jng");
    m_pcmdOpcodeJNG->setToolTip("Добавить jng");
    m_pcmdOpcodeJNLE = new QPushButton("jnle");
    m_pcmdOpcodeJNLE->setToolTip("Добавить jnle");
    m_pcmdOpcodeJG = new QPushButton("jg");
    m_pcmdOpcodeJG->setToolTip("Добавить jg");
    m_pcmdOpcodeJB = new QPushButton("jb");
    m_pcmdOpcodeJB->setToolTip("Добавить jb");
    m_pcmdOpcodeJNAE = new QPushButton("jnae");
    m_pcmdOpcodeJNAE->setToolTip("Добавить jnae");
    m_pcmdOpcodeJC = new QPushButton("jc");
    m_pcmdOpcodeJC->setToolTip("Добавить jc");
    m_pcmdOpcodeJBE = new QPushButton("jbe");
    m_pcmdOpcodeJBE->setToolTip("Добавить jbe");
    m_pcmdOpcodeJNA = new QPushButton("jna");
    m_pcmdOpcodeJNA->setToolTip("Добавить jna");
    m_pcmdOpcodeJNB = new QPushButton("jnb");
    m_pcmdOpcodeJNB->setToolTip("Добавить jnb");
    m_pcmdOpcodeJAE = new QPushButton("jae");
    m_pcmdOpcodeJAE->setToolTip("Добавить jae");
    m_pcmdOpcodeJNC = new QPushButton("jnc");
    m_pcmdOpcodeJNC->setToolTip("Добавить jnc");
    m_pcmdOpcodeJNBE = new QPushButton("jnbe");
    m_pcmdOpcodeJNBE->setToolTip("Добавить jnbe");
    m_pcmdOpcodeJA = new QPushButton("ja");
    m_pcmdOpcodeJA->setToolTip("Добавить ja");
    m_pcmdOpcodeJE = new QPushButton("je");
    m_pcmdOpcodeJE->setToolTip("Добавить je");
    m_pcmdOpcodeJZ = new QPushButton("jz");
    m_pcmdOpcodeJZ->setToolTip("Добавить jz");
    m_pcmdOpcodeJP = new QPushButton("jp");
    m_pcmdOpcodeJP->setToolTip("Добавить jp");
    m_pcmdOpcodeJPE = new QPushButton("jpe");
    m_pcmdOpcodeJPE->setToolTip("Добавить jpe");
    m_pcmdOpcodeJO = new QPushButton("jo");
    m_pcmdOpcodeJO->setToolTip("Добавить jo");
    m_pcmdOpcodeJS = new QPushButton("js");
    m_pcmdOpcodeJS->setToolTip("Добавить js");
    m_pcmdOpcodeJNE = new QPushButton("jne");
    m_pcmdOpcodeJNE->setToolTip("Добавить jne");
    m_pcmdOpcodeJNZ = new QPushButton("jnz");
    m_pcmdOpcodeJNZ->setToolTip("Добавить jnz");
    m_pcmdOpcodeJNP = new QPushButton("jnp");
    m_pcmdOpcodeJNP->setToolTip("Добавить jnp");
    m_pcmdOpcodeJPO = new QPushButton("jpo");
    m_pcmdOpcodeJPO->setToolTip("Добавить jpo");
    m_pcmdOpcodeJNO = new QPushButton("jno");
    m_pcmdOpcodeJNO->setToolTip("Добавить jno");
    m_pcmdOpcodeJNS = new QPushButton("jns");
    m_pcmdOpcodeJNS->setToolTip("Добавить jns");
    m_pcmdOpcodeJCXZ = new QPushButton("jcxz");
    m_pcmdOpcodeJCXZ->setToolTip("Добавить jcxz");

    QGridLayout* pgridCondJumpCommands = new QGridLayout();
    pgridCondJumpCommands->setSpacing(0);
    pgridCondJumpCommands->addWidget(m_pcmdOpcodeJL, 0, 0);    //  опкоды
    pgridCondJumpCommands->addWidget(m_pcmdOpcodeJNGE, 1, 0);
    pgridCondJumpCommands->addWidget(m_pcmdOpcodeJNL, 2, 0);
    pgridCondJumpCommands->addWidget(m_pcmdOpcodeJGE, 3, 0);
    pgridCondJumpCommands->addWidget(m_pcmdOpcodeJLE, 4, 0);
    pgridCondJumpCommands->addWidget(m_pcmdOpcodeJNG, 5, 0);
    pgridCondJumpCommands->addWidget(m_pcmdOpcodeJNLE, 6, 0);
    pgridCondJumpCommands->addWidget(m_pcmdOpcodeJG, 7, 0);
    pgridCondJumpCommands->addWidget(m_pcmdOpcodeJB, 8, 0);
    pgridCondJumpCommands->addWidget(m_pcmdOpcodeJNAE, 9, 0);
    pgridCondJumpCommands->addWidget(m_pcmdOpcodeJC, 10, 0);
    pgridCondJumpCommands->addWidget(m_pcmdOpcodeJBE, 0, 1);
    pgridCondJumpCommands->addWidget(m_pcmdOpcodeJNA, 1, 1);
    pgridCondJumpCommands->addWidget(m_pcmdOpcodeJNB, 2, 1);
    pgridCondJumpCommands->addWidget(m_pcmdOpcodeJAE, 3, 1);
    pgridCondJumpCommands->addWidget(m_pcmdOpcodeJNC, 4, 1);
    pgridCondJumpCommands->addWidget(m_pcmdOpcodeJNBE, 5, 1);
    pgridCondJumpCommands->addWidget(m_pcmdOpcodeJA, 6, 1);
    pgridCondJumpCommands->addWidget(m_pcmdOpcodeJE, 7, 1);
    pgridCondJumpCommands->addWidget(m_pcmdOpcodeJZ, 8, 1);
    pgridCondJumpCommands->addWidget(m_pcmdOpcodeJP, 9, 1);
    pgridCondJumpCommands->addWidget(m_pcmdOpcodeJPE, 0, 2);
    pgridCondJumpCommands->addWidget(m_pcmdOpcodeJO, 1, 2);
    pgridCondJumpCommands->addWidget(m_pcmdOpcodeJS, 2, 2);
    pgridCondJumpCommands->addWidget(m_pcmdOpcodeJNE, 3, 2);
    pgridCondJumpCommands->addWidget(m_pcmdOpcodeJNZ, 4, 2);
    pgridCondJumpCommands->addWidget(m_pcmdOpcodeJNP, 5, 2);
    pgridCondJumpCommands->addWidget(m_pcmdOpcodeJPO, 6, 2);
    pgridCondJumpCommands->addWidget(m_pcmdOpcodeJNO, 7, 2);
    pgridCondJumpCommands->addWidget(m_pcmdOpcodeJNS, 8, 2);
    pgridCondJumpCommands->addWidget(m_pcmdOpcodeJCXZ, 9, 2);
    QMenu* pmenuCondJumpCommands = new QMenu(m_pcmdCondJumpCommands);
    pmenuCondJumpCommands->setLayout(pgridCondJumpCommands);
    m_pcmdCondJumpCommands->setMenu(pmenuCondJumpCommands);

    //  --  управление циклом
    m_pcmdOpcodeLOOP = new QPushButton("loop");
    m_pcmdOpcodeLOOP->setToolTip("Добавить loop");
    m_pcmdOpcodeLOOPE = new QPushButton("loope");
    m_pcmdOpcodeLOOPE->setToolTip("Добавить loope");
    m_pcmdOpcodeLOOPZ = new QPushButton("loopz");
    m_pcmdOpcodeLOOPZ->setToolTip("Добавить loopz");
    m_pcmdOpcodeLOOPNE = new QPushButton("loopne");
    m_pcmdOpcodeLOOPNE->setToolTip("Добавить loopne");
    m_pcmdOpcodeLOOPNZ = new QPushButton("loopnz");
    m_pcmdOpcodeLOOPNZ->setToolTip("Добавить loopnz");

    QGridLayout* pgridCycleManageCommands = new QGridLayout();
    pgridCycleManageCommands->setSpacing(0);
    pgridCycleManageCommands->addWidget(m_pcmdOpcodeLOOP, 0, 0);  //  опкоды
    pgridCycleManageCommands->addWidget(m_pcmdOpcodeLOOPE, 1, 0);
    pgridCycleManageCommands->addWidget(m_pcmdOpcodeLOOPZ, 2, 0);
    pgridCycleManageCommands->addWidget(m_pcmdOpcodeLOOPNE, 0, 1);
    pgridCycleManageCommands->addWidget(m_pcmdOpcodeLOOPNZ, 1, 1);
    QMenu* pmenuCycleManageCommands = new QMenu(m_pcmdCycleManageCommands);
    pmenuCycleManageCommands->setLayout(pgridCycleManageCommands);
    m_pcmdCycleManageCommands->setMenu(pmenuCycleManageCommands);

    //  --  прерывания
    m_pcmdOpcodeINT = new QPushButton("int");
    m_pcmdOpcodeINT->setToolTip("Добавить int");
    m_pcmdOpcodeINTO = new QPushButton("into");
    m_pcmdOpcodeINTO->setToolTip("Добавить into");

    QVBoxLayout* pvblInterruptCommands = new QVBoxLayout();
    pvblInterruptCommands->setSpacing(0);
    pvblInterruptCommands->addWidget(m_pcmdOpcodeINT);  //  опкоды
    pvblInterruptCommands->addWidget(m_pcmdOpcodeINTO);
    QMenu* pmenuInterruptCommands = new QMenu(m_pcmdInterruptCommands);
    pmenuInterruptCommands->setLayout(pvblInterruptCommands);
    m_pcmdInterruptCommands->setMenu(pmenuInterruptCommands);

    //  --  установка флажков
    m_pcmdOpcodeCLC = new QPushButton("clc");
    m_pcmdOpcodeCLC->setToolTip("Добавить clc");
    m_pcmdOpcodeSTC = new QPushButton("stc");
    m_pcmdOpcodeSTC->setToolTip("Добавить stc");
    m_pcmdOpcodeCMC = new QPushButton("cmc");
    m_pcmdOpcodeCMC->setToolTip("Добавить cmc");
    m_pcmdOpcodeCLD = new QPushButton("cld");
    m_pcmdOpcodeCLD->setToolTip("Добавить cld");
    m_pcmdOpcodeSTD = new QPushButton("std");
    m_pcmdOpcodeSTD->setToolTip("Добавить std");
    m_pcmdOpcodeCLI = new QPushButton("cli");
    m_pcmdOpcodeCLI->setToolTip("Добавить cli");
    m_pcmdOpcodeSTI = new QPushButton("sti");
    m_pcmdOpcodeSTI->setToolTip("Добавить sti");

    QGridLayout* pgridFlagsCommands = new QGridLayout();
    pgridFlagsCommands->setSpacing(0);
    pgridFlagsCommands->addWidget(m_pcmdOpcodeCLC, 0, 0);  //  опкоды
    pgridFlagsCommands->addWidget(m_pcmdOpcodeSTC, 1, 0);
    pgridFlagsCommands->addWidget(m_pcmdOpcodeCMC, 2, 0);
    pgridFlagsCommands->addWidget(m_pcmdOpcodeCLD, 3, 0);
    pgridFlagsCommands->addWidget(m_pcmdOpcodeSTD, 0, 1);
    pgridFlagsCommands->addWidget(m_pcmdOpcodeCLI, 1, 1);
    pgridFlagsCommands->addWidget(m_pcmdOpcodeSTI, 2, 1);
    QMenu* pmenuFlagsCommands = new QMenu(m_pcmdFlagsCommands);
    pmenuFlagsCommands->setLayout(pgridFlagsCommands);
    m_pcmdFlagsCommands->setMenu(pmenuFlagsCommands);

    //  --  специальные
    m_pcmdOpcodeHLT = new QPushButton("hlt");
    m_pcmdOpcodeHLT->setToolTip("Добавить hlt");
    m_pcmdOpcodeWAIT = new QPushButton("wait");
    m_pcmdOpcodeWAIT->setToolTip("Добавить wait");
    m_pcmdOpcodeLOCK = new QPushButton("lock");
    m_pcmdOpcodeLOCK->setToolTip("Добавить lock");
    m_pcmdOpcodeESC = new QPushButton("esc");
    m_pcmdOpcodeESC->setToolTip("Добавить esc");
    m_pcmdOpcodeNOP = new QPushButton("nop");
    m_pcmdOpcodeNOP->setToolTip("Добавить nop");

    QGridLayout* pgridSpecialCommands = new QGridLayout();
    pgridSpecialCommands->setSpacing(0);
    pgridSpecialCommands->addWidget(m_pcmdOpcodeHLT, 0, 0);    //  опкоды
    pgridSpecialCommands->addWidget(m_pcmdOpcodeWAIT, 1, 0);
    pgridSpecialCommands->addWidget(m_pcmdOpcodeLOCK, 2, 0);
    pgridSpecialCommands->addWidget(m_pcmdOpcodeESC, 0, 1);
    pgridSpecialCommands->addWidget(m_pcmdOpcodeNOP, 1, 1);
    QMenu* pmenuSpecialCommands = new QMenu(m_pcmdSpecialCommands);
    pmenuSpecialCommands->setLayout(pgridSpecialCommands);
    m_pcmdSpecialCommands->setMenu(pmenuSpecialCommands);

    //  --  префиксы rep
    m_pcmdOpcodeRepMovs = new QPushButton("rep movs");
    m_pcmdOpcodeRepMovs->setToolTip("Добавить rep movs");
    m_pcmdOpcodeRepStos = new QPushButton("rep stos");
    m_pcmdOpcodeRepStos->setToolTip("Добавить rep stos");
    m_pcmdOpcodeRepeCmps = new QPushButton("repe cmps");
    m_pcmdOpcodeRepeCmps->setToolTip("Добавить repe cmps");
    m_pcmdOpcodeRepeScas = new QPushButton("repe scas");
    m_pcmdOpcodeRepeScas->setToolTip("Добавить repe scas");
    m_pcmdOpcodeRepzCmps = new QPushButton("repz cmps");
    m_pcmdOpcodeRepzCmps->setToolTip("Добавить repz cmps");
    m_pcmdOpcodeRepzScas = new QPushButton("repz scas");
    m_pcmdOpcodeRepzScas->setToolTip("Добавить repz scas");
    m_pcmdOpcodeRepneMovs = new QPushButton("repne movs");
    m_pcmdOpcodeRepneMovs->setToolTip("Добавить repne movs");
    m_pcmdOpcodeRepneStos = new QPushButton("repne stos");
    m_pcmdOpcodeRepneStos->setToolTip("Добавить repne stos");
    m_pcmdOpcodeRepnzCmps = new QPushButton("repnz cmps");
    m_pcmdOpcodeRepnzCmps->setToolTip("Добавить repnz cmps");
    m_pcmdOpcodeRepnzScas = new QPushButton("repnz scas");
    m_pcmdOpcodeRepnzScas->setToolTip("Добавить repnz scas");

    QGridLayout* pgridPrefixCommands = new QGridLayout();
    pgridPrefixCommands->setSpacing(0);
    pgridPrefixCommands->addWidget(m_pcmdOpcodeRepMovs, 0, 0);  //  опкоды
    pgridPrefixCommands->addWidget(m_pcmdOpcodeRepStos, 1, 0);
    pgridPrefixCommands->addWidget(m_pcmdOpcodeRepeCmps, 2, 0);
    pgridPrefixCommands->addWidget(m_pcmdOpcodeRepeScas, 3, 0);
    pgridPrefixCommands->addWidget(m_pcmdOpcodeRepzCmps, 4, 0);
    pgridPrefixCommands->addWidget(m_pcmdOpcodeRepzScas, 0, 1);
    pgridPrefixCommands->addWidget(m_pcmdOpcodeRepneMovs, 1, 1);
    pgridPrefixCommands->addWidget(m_pcmdOpcodeRepneStos, 2, 1);
    pgridPrefixCommands->addWidget(m_pcmdOpcodeRepnzCmps, 3, 1);
    pgridPrefixCommands->addWidget(m_pcmdOpcodeRepnzScas, 4, 1);
    QMenu* pmenuPrefixCommands = new QMenu(m_pcmdPrefixCommmands);
    pmenuPrefixCommands->setLayout(pgridPrefixCommands);
    m_pcmdPrefixCommmands->setMenu(pmenuPrefixCommands);




    //Comment
    m_pcmdAddComment = new QPushButton("+ Комментарий");

    m_pcmdSaveFile = new QPushButton("Сохранить");
    m_pcmdOpenFile = new QPushButton("Открыть");

    m_pcmdQuit = new QPushButton("Выход");

    //number of line
    m_pcmdLineUp = new QPushButton("+");
    m_pcmdLineDown = new QPushButton("-");
    m_plcdNumberOfLine = new QLCDNumber();
    m_plcdNumberOfLine->setSegmentStyle(QLCDNumber::Flat);    
    m_plcdNumberOfLine->setDigitCount(4);
    m_plcdNumberOfLine->setFrameStyle(QFrame::NoFrame);
    m_plcdNumberOfLine->setFixedHeight(50);
    m_plcdNumberOfLine->display(1);
    this->m_nNumberOfLine = 1;
    QVBoxLayout* pvblNumbersOfLine = new QVBoxLayout();
    pvblNumbersOfLine->addWidget(m_pcmdLineDown);
    pvblNumbersOfLine->addWidget(m_plcdNumberOfLine);
    pvblNumbersOfLine->addWidget(m_pcmdLineUp);
    pvblNumbersOfLine->setSpacing(0);

    pvblLeftPanel->addWidget(m_pcmdAddData, Qt::AlignTop);
    pvblLeftPanel->addWidget(m_pcmdAddOpcode, Qt::AlignTop);
    pvblLeftPanel->addWidget(m_pcmdAddLabel, Qt::AlignTop);
    pvblLeftPanel->addWidget(m_pcmdAddDirective, Qt::AlignTop);
    pvblLeftPanel->addWidget(m_pcmdAddComment, Qt::AlignTop);
    pvblLeftPanel->addStretch(1);
    pvblLeftPanel->addLayout(pvblNumbersOfLine);
    pvblLeftPanel->addStretch(1);
    pvblLeftPanel->addWidget(m_pcmdSaveFile, Qt::AlignBottom);
    pvblLeftPanel->addWidget(m_pcmdOpenFile, Qt::AlignBottom);
    pvblLeftPanel->addWidget(m_pcmdQuit, Qt::AlignBottom);
#ifdef Q_OS_WIN
    QGroupBox* pgbLeftPanel = new QGroupBox("Инструменты");
#elif defined(Q_OS_LINUX)
    QGroupBox* pgbLeftPanel = new QGroupBox();
#endif
    pgbLeftPanel->setLayout(pvblLeftPanel);

#ifdef Q_OS_LINUX
    pgbLeftPanel->setFlat(true);

    QDockWidget* pdockLeftPanel = new QDockWidget();
    pdockLeftPanel->setWidget(pgbLeftPanel);
    pdockLeftPanel->setFeatures(QDockWidget::NoDockWidgetFeatures);
    addDockWidget(Qt::LeftDockWidgetArea, pdockLeftPanel);
#endif

    m_pteSource = new QTextEdit();
    m_pteSource->setReadOnly(true);
    m_pslContent = new QStackedLayout();
    m_pgbContent = new QGroupBox();
    m_pgbContent->setLayout(m_pslContent);
    m_pvblCentral = new QVBoxLayout();

    //m_pteSource->setText(";This source code created by \"OptAsm v1.0\"\n");

    m_pvblCentral->addWidget(m_pgbContent, Qt::AlignTop);
    m_pvblCentral->addLayout(phblOkCancel);
    m_pvblCentral->addWidget(m_pteSource, Qt::AlignBottom);

#ifdef Q_OS_WIN
    QHBoxLayout* phblGeneral = new QHBoxLayout();
    phblGeneral->addWidget(pgbLeftPanel);
    phblGeneral->addLayout(m_pvblCentral);
#endif

    QGroupBox* pgbCentralPanel = new QGroupBox();
#ifdef Q_OS_LINUX
    pgbCentralPanel->setLayout(m_pvblCentral);
#elif defined(Q_OS_WIN)
    pgbCentralPanel->setLayout(phblGeneral);
#endif
    pgbCentralPanel->setFlat(true);

    setCentralWidget(pgbCentralPanel);

    loadAllPanels();

    connect(m_pcmdLabelGlobal, SIGNAL(pressed()), SLOT(makeLabelGlobal()));
    connect(m_pcmdLabelGlobal, SIGNAL(pressed()), pmenuLabels, SLOT(hide()));
    //connect(m_plabelGlobal->m_pleLabelName, SIGNAL(returnPressed()), this, SLOT(lineAdd()), Qt::QueuedConnection);
    connect(m_plabelGlobal->m_pleLabelName, SIGNAL(returnPressed()), this, SLOT(lineAdd()));
    //connect(m_plabelGlobal->m_pleLabelName, SIGNAL(returnPressed()), m_pcmdAddString, SIGNAL(clicked()), Qt::QueuedConnection);

    connect(m_pcmdLabelLocal, SIGNAL(pressed()), SLOT(makeLabelLocal()));
    connect(m_pcmdLabelLocal, SIGNAL(pressed()), pmenuLabels, SLOT(hide()));
    connect(m_plabelLocal->m_pleLabelName, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdLabelUnnamed, SIGNAL(pressed()), SLOT(makeLabelUnnamed()));
    connect(m_pcmdLabelUnnamed, SIGNAL(pressed()), pmenuLabels, SLOT(hide()));

    connect(m_pcmdLineUp, SIGNAL(clicked()), SLOT(lineUp()));
    connect(m_pcmdLineDown, SIGNAL(clicked()), SLOT(lineDown()));
    connect(m_pcmdAddString, SIGNAL(clicked()), SLOT(lineAdd()));
    connect(m_pcmdCancel, SIGNAL(clicked()), SLOT(lineCancel()));

    connect(m_pcmdDataSingle, SIGNAL(pressed()), SLOT(makeDataSingle()));
    connect(m_pcmdDataSingle, SIGNAL(pressed()), pmenuDatas, SLOT(hide()));

    connect(m_pcmdDataDup, SIGNAL(pressed()), SLOT(makeDataDup()));
    connect(m_pcmdDataDup, SIGNAL(pressed()), pmenuDatas, SLOT(hide()));

    connect(m_pcmdAddComment, SIGNAL(pressed()), SLOT(makeComment()));
    connect(m_pcomment->m_pleComment, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeMOV, SIGNAL(pressed()), SLOT(makeOpcodeMOV()));
    connect(m_pcmdOpcodeMOV, SIGNAL(pressed()), pmenuMoveDataCommands, SLOT(hide()));
    connect(m_pcmdOpcodeMOV, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeMOV->m_pleOp2, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeXCHG, SIGNAL(pressed()), SLOT(makeOpcodeXCHG()));
    connect(m_pcmdOpcodeXCHG, SIGNAL(pressed()), pmenuMoveDataCommands, SLOT(hide()));
    connect(m_pcmdOpcodeXCHG, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeXCHG->m_pleOp2, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeXLAT, SIGNAL(pressed()), SLOT(makeOpcodeXLAT()));
    connect(m_pcmdOpcodeXLAT, SIGNAL(pressed()), pmenuMoveDataCommands, SLOT(hide()));
    connect(m_pcmdOpcodeXLAT, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));

    connect(m_pcmdOpcodeLEA, SIGNAL(pressed()), SLOT(makeOpcodeLEA()));
    connect(m_pcmdOpcodeLEA, SIGNAL(pressed()), pmenuMoveDataCommands, SLOT(hide()));
    connect(m_pcmdOpcodeLEA, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeLEA->m_pleOp2, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeLDS, SIGNAL(pressed()), SLOT(makeOpcodeLDS()));
    connect(m_pcmdOpcodeLDS, SIGNAL(pressed()), pmenuMoveDataCommands, SLOT(hide()));
    connect(m_pcmdOpcodeLDS, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeLDS->m_pleOp2, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeLES, SIGNAL(pressed()), SLOT(makeOpcodeLES()));
    connect(m_pcmdOpcodeLES, SIGNAL(pressed()), pmenuMoveDataCommands, SLOT(hide()));
    connect(m_pcmdOpcodeLES, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeLES->m_pleOp2, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeLAHF, SIGNAL(pressed()), SLOT(makeOpcodeLAHF()));
    connect(m_pcmdOpcodeLAHF, SIGNAL(pressed()), pmenuSendFlagsCommands, SLOT(hide()));
    connect(m_pcmdOpcodeLAHF, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));

    connect(m_pcmdOpcodeSAHF, SIGNAL(pressed()), SLOT(makeOpcodeSAHF()));
    connect(m_pcmdOpcodeSAHF, SIGNAL(pressed()), pmenuSendFlagsCommands, SLOT(hide()));
    connect(m_pcmdOpcodeSAHF, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));

    connect(m_pcmdOpcodePUSH, SIGNAL(pressed()), SLOT(makeOpcodePUSH()));
    connect(m_pcmdOpcodePUSH, SIGNAL(pressed()), pmenuStackCommands, SLOT(hide()));
    connect(m_pcmdOpcodePUSH, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodePUSH->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodePOP, SIGNAL(pressed()), SLOT(makeOpcodePOP()));
    connect(m_pcmdOpcodePOP, SIGNAL(pressed()), pmenuStackCommands, SLOT(hide()));
    connect(m_pcmdOpcodePOP, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodePOP->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodePUSHF, SIGNAL(pressed()), SLOT(makeOpcodePUSHF()));
    connect(m_pcmdOpcodePUSHF, SIGNAL(pressed()), pmenuStackCommands, SLOT(hide()));
    connect(m_pcmdOpcodePUSHF, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));

    connect(m_pcmdOpcodePOPF, SIGNAL(pressed()), SLOT(makeOpcodePOPF()));
    connect(m_pcmdOpcodePOPF, SIGNAL(pressed()), pmenuStackCommands, SLOT(hide()));
    connect(m_pcmdOpcodePOPF, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));

    connect(m_pcmdOpcodeIN, SIGNAL(pressed()), SLOT(makeOpcodeIN()));
    connect(m_pcmdOpcodeIN, SIGNAL(pressed()), pmenuIOCommands, SLOT(hide()));
    connect(m_pcmdOpcodeIN, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeIN->m_pleOp2, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeOUT, SIGNAL(pressed()), SLOT(makeOpcodeOUT()));
    connect(m_pcmdOpcodeOUT, SIGNAL(pressed()), pmenuIOCommands, SLOT(hide()));
    connect(m_pcmdOpcodeOUT, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeOUT->m_pleOp2, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeADD, SIGNAL(pressed()), SLOT(makeOpcodeADD()));
    connect(m_pcmdOpcodeADD, SIGNAL(pressed()), pmenuAddingCommands, SLOT(hide()));
    connect(m_pcmdOpcodeADD, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeADD->m_pleOp2, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeADC, SIGNAL(pressed()), SLOT(makeOpcodeADC()));
    connect(m_pcmdOpcodeADC, SIGNAL(pressed()), pmenuAddingCommands, SLOT(hide()));
    connect(m_pcmdOpcodeADC, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeADC->m_pleOp2, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeSUB, SIGNAL(pressed()), SLOT(makeOpcodeSUB()));
    connect(m_pcmdOpcodeSUB, SIGNAL(pressed()), pmenuSubtractCommands, SLOT(hide()));
    connect(m_pcmdOpcodeSUB, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeSUB->m_pleOp2, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeSBB, SIGNAL(pressed()), SLOT(makeOpcodeSBB()));
    connect(m_pcmdOpcodeSBB, SIGNAL(pressed()), pmenuSubtractCommands, SLOT(hide()));
    connect(m_pcmdOpcodeSBB, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeSBB->m_pleOp2, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeCMP, SIGNAL(pressed()), SLOT(makeOpcodeCMP()));
    connect(m_pcmdOpcodeCMP, SIGNAL(pressed()), pmenuSubtractCommands, SLOT(hide()));
    connect(m_pcmdOpcodeCMP, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeCMP->m_pleOp2, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeMUL, SIGNAL(pressed()), SLOT(makeOpcodeMUL()));
    connect(m_pcmdOpcodeMUL, SIGNAL(pressed()), pmenuMulDivCommands, SLOT(hide()));
    connect(m_pcmdOpcodeMUL, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeMUL->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeIMUL, SIGNAL(pressed()), SLOT(makeOpcodeIMUL()));
    connect(m_pcmdOpcodeIMUL, SIGNAL(pressed()), pmenuMulDivCommands, SLOT(hide()));
    connect(m_pcmdOpcodeIMUL, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeIMUL->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeDIV, SIGNAL(pressed()), SLOT(makeOpcodeDIV()));
    connect(m_pcmdOpcodeDIV, SIGNAL(pressed()), pmenuMulDivCommands, SLOT(hide()));
    connect(m_pcmdOpcodeDIV, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeDIV->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeIDIV, SIGNAL(pressed()), SLOT(makeOpcodeIDIV()));
    connect(m_pcmdOpcodeIDIV, SIGNAL(pressed()), pmenuMulDivCommands, SLOT(hide()));
    connect(m_pcmdOpcodeIDIV, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeIDIV->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeINC, SIGNAL(pressed()), SLOT(makeOpcodeINC()));
    connect(m_pcmdOpcodeINC, SIGNAL(pressed()), pmenuSingleOpArithmCommands, SLOT(hide()));
    connect(m_pcmdOpcodeINC, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeINC->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeDEC, SIGNAL(pressed()), SLOT(makeOpcodeDEC()));
    connect(m_pcmdOpcodeDEC, SIGNAL(pressed()), pmenuSingleOpArithmCommands, SLOT(hide()));
    connect(m_pcmdOpcodeDEC, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeDEC->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeNEG, SIGNAL(pressed()), SLOT(makeOpcodeNEG()));
    connect(m_pcmdOpcodeNEG, SIGNAL(pressed()), pmenuSingleOpArithmCommands, SLOT(hide()));
    connect(m_pcmdOpcodeNEG, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeNEG->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeCBW, SIGNAL(pressed()), SLOT(makeOpcodeCBW()));
    connect(m_pcmdOpcodeCBW, SIGNAL(pressed()), pmenuTransformCommands, SLOT(hide()));
    connect(m_pcmdOpcodeCBW, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));

    connect(m_pcmdOpcodeCWD, SIGNAL(pressed()), SLOT(makeOpcodeCWD()));
    connect(m_pcmdOpcodeCWD, SIGNAL(pressed()), pmenuTransformCommands, SLOT(hide()));
    connect(m_pcmdOpcodeCWD, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));

    connect(m_pcmdOpcodeDAA, SIGNAL(pressed()), SLOT(makeOpcodeDAA()));
    connect(m_pcmdOpcodeDAA, SIGNAL(pressed()), pmenuDecCorrection, SLOT(hide()));
    connect(m_pcmdOpcodeDAA, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));

    connect(m_pcmdOpcodeDAS, SIGNAL(pressed()), SLOT(makeOpcodeDAS()));
    connect(m_pcmdOpcodeDAS, SIGNAL(pressed()), pmenuDecCorrection, SLOT(hide()));
    connect(m_pcmdOpcodeDAS, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));

    connect(m_pcmdOpcodeAAA, SIGNAL(pressed()), SLOT(makeOpcodeAAA()));
    connect(m_pcmdOpcodeAAA, SIGNAL(pressed()), pmenuSymbolCorrectionCommands, SLOT(hide()));
    connect(m_pcmdOpcodeAAA, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));

    connect(m_pcmdOpcodeAAS, SIGNAL(pressed()), SLOT(makeOpcodeAAS()));
    connect(m_pcmdOpcodeAAS, SIGNAL(pressed()), pmenuSymbolCorrectionCommands, SLOT(hide()));
    connect(m_pcmdOpcodeAAS, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));

    connect(m_pcmdOpcodeAAM, SIGNAL(pressed()), SLOT(makeOpcodeAAM()));
    connect(m_pcmdOpcodeAAM, SIGNAL(pressed()), pmenuSymbolCorrectionCommands, SLOT(hide()));
    connect(m_pcmdOpcodeAAM, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));

    connect(m_pcmdOpcodeAAD, SIGNAL(pressed()), SLOT(makeOpcodeAAD()));
    connect(m_pcmdOpcodeAAD, SIGNAL(pressed()), pmenuSymbolCorrectionCommands, SLOT(hide()));
    connect(m_pcmdOpcodeAAD, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));

    connect(m_pcmdOpcodeAND, SIGNAL(pressed()), SLOT(makeOpcodeAND()));
    connect(m_pcmdOpcodeAND, SIGNAL(pressed()), pmenuLogicCommands, SLOT(hide()));
    connect(m_pcmdOpcodeAND, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeAND->m_pleOp2, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeOR, SIGNAL(pressed()), SLOT(makeOpcodeOR()));
    connect(m_pcmdOpcodeOR, SIGNAL(pressed()), pmenuLogicCommands, SLOT(hide()));
    connect(m_pcmdOpcodeOR, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeOR->m_pleOp2, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeXOR, SIGNAL(pressed()), SLOT(makeOpcodeXOR()));
    connect(m_pcmdOpcodeXOR, SIGNAL(pressed()), pmenuLogicCommands, SLOT(hide()));
    connect(m_pcmdOpcodeXOR, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeXOR->m_pleOp2, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeNOT, SIGNAL(pressed()), SLOT(makeOpcodeNOT()));
    connect(m_pcmdOpcodeNOT, SIGNAL(pressed()), pmenuLogicCommands, SLOT(hide()));
    connect(m_pcmdOpcodeNOT, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeNOT->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeTEST, SIGNAL(pressed()), SLOT(makeOpcodeTEST()));
    connect(m_pcmdOpcodeTEST, SIGNAL(pressed()), pmenuLogicCommands, SLOT(hide()));
    connect(m_pcmdOpcodeTEST, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeTEST->m_pleOp2, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeRCL, SIGNAL(pressed()), SLOT(makeOpcodeRCL()));
    connect(m_pcmdOpcodeRCL, SIGNAL(pressed()), pmenuShiftCommands, SLOT(hide()));
    connect(m_pcmdOpcodeRCL, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeRCL->m_pleOp2, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeRCR, SIGNAL(pressed()), SLOT(makeOpcodeRCR()));
    connect(m_pcmdOpcodeRCR, SIGNAL(pressed()), pmenuShiftCommands, SLOT(hide()));
    connect(m_pcmdOpcodeRCR, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeRCR->m_pleOp2, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeROL, SIGNAL(pressed()), SLOT(makeOpcodeROL()));
    connect(m_pcmdOpcodeROL, SIGNAL(pressed()), pmenuShiftCommands, SLOT(hide()));
    connect(m_pcmdOpcodeROL, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeROL->m_pleOp2, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeROR, SIGNAL(pressed()), SLOT(makeOpcodeROR()));
    connect(m_pcmdOpcodeROR, SIGNAL(pressed()), pmenuShiftCommands, SLOT(hide()));
    connect(m_pcmdOpcodeROR, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeROR->m_pleOp2, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeSAL, SIGNAL(pressed()), SLOT(makeOpcodeSAL()));
    connect(m_pcmdOpcodeSAL, SIGNAL(pressed()), pmenuShiftCommands, SLOT(hide()));
    connect(m_pcmdOpcodeSAL, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeSAL->m_pleOp2, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeSAR, SIGNAL(pressed()), SLOT(makeOpcodeSAR()));
    connect(m_pcmdOpcodeSAR, SIGNAL(pressed()), pmenuShiftCommands, SLOT(hide()));
    connect(m_pcmdOpcodeSAR, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeSAR->m_pleOp2, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeSHL, SIGNAL(pressed()), SLOT(makeOpcodeSHL()));
    connect(m_pcmdOpcodeSHL, SIGNAL(pressed()), pmenuShiftCommands, SLOT(hide()));
    connect(m_pcmdOpcodeSHL, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeSHL->m_pleOp2, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeSHR, SIGNAL(pressed()), SLOT(makeOpcodeSHR()));
    connect(m_pcmdOpcodeSHR, SIGNAL(pressed()), pmenuShiftCommands, SLOT(hide()));
    connect(m_pcmdOpcodeSHR, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeSHR->m_pleOp2, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeBT, SIGNAL(pressed()), SLOT(makeOpcodeBT()));
    connect(m_pcmdOpcodeBT, SIGNAL(pressed()), pmenuBitCommands, SLOT(hide()));
    connect(m_pcmdOpcodeBT, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeBT->m_pleOp2, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeBTC, SIGNAL(pressed()), SLOT(makeOpcodeBTC()));
    connect(m_pcmdOpcodeBTC, SIGNAL(pressed()), pmenuBitCommands, SLOT(hide()));
    connect(m_pcmdOpcodeBTC, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeBTC->m_pleOp2, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeBTR, SIGNAL(pressed()), SLOT(makeOpcodeBTR()));
    connect(m_pcmdOpcodeBTR, SIGNAL(pressed()), pmenuBitCommands, SLOT(hide()));
    connect(m_pcmdOpcodeBTR, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeBTR->m_pleOp2, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeBTS, SIGNAL(pressed()), SLOT(makeOpcodeBTS()));
    connect(m_pcmdOpcodeBTS, SIGNAL(pressed()), pmenuBitCommands, SLOT(hide()));
    connect(m_pcmdOpcodeBTS, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeBTS->m_pleOp2, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeJMP, SIGNAL(pressed()), SLOT(makeOpcodeJMP()));
    connect(m_pcmdOpcodeJMP, SIGNAL(pressed()), pmenuUncondJumpCommands, SLOT(hide()));
    connect(m_pcmdOpcodeJMP, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeJMP->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeCALL, SIGNAL(pressed()), SLOT(makeOpcodeCALL()));
    connect(m_pcmdOpcodeCALL, SIGNAL(pressed()), pmenuUncondJumpCommands, SLOT(hide()));
    connect(m_pcmdOpcodeCALL, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeCALL->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeRET, SIGNAL(pressed()), SLOT(makeOpcodeRET()));
    connect(m_pcmdOpcodeRET, SIGNAL(pressed()), pmenuUncondJumpCommands, SLOT(hide()));
    connect(m_pcmdOpcodeRET, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeRET->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeJL, SIGNAL(pressed()), SLOT(makeOpcodeJL()));
    connect(m_pcmdOpcodeJL, SIGNAL(pressed()), pmenuCondJumpCommands, SLOT(hide()));
    connect(m_pcmdOpcodeJL, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeJL->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeJNGE, SIGNAL(pressed()), SLOT(makeOpcodeJNGE()));
    connect(m_pcmdOpcodeJNGE, SIGNAL(pressed()), pmenuCondJumpCommands, SLOT(hide()));
    connect(m_pcmdOpcodeJNGE, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeJNGE->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeJNL, SIGNAL(pressed()), SLOT(makeOpcodeJNL()));
    connect(m_pcmdOpcodeJNL, SIGNAL(pressed()), pmenuCondJumpCommands, SLOT(hide()));
    connect(m_pcmdOpcodeJNL, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeJNL->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeJGE, SIGNAL(pressed()), SLOT(makeOpcodeJGE()));
    connect(m_pcmdOpcodeJGE, SIGNAL(pressed()), pmenuCondJumpCommands, SLOT(hide()));
    connect(m_pcmdOpcodeJGE, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeJGE->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeJLE, SIGNAL(pressed()), SLOT(makeOpcodeJLE()));
    connect(m_pcmdOpcodeJLE, SIGNAL(pressed()), pmenuCondJumpCommands, SLOT(hide()));
    connect(m_pcmdOpcodeJLE, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeJLE->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeJNG, SIGNAL(pressed()), SLOT(makeOpcodeJNG()));
    connect(m_pcmdOpcodeJNG, SIGNAL(pressed()), pmenuCondJumpCommands, SLOT(hide()));
    connect(m_pcmdOpcodeJNG, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeJNG->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeJNLE, SIGNAL(pressed()), SLOT(makeOpcodeJNLE()));
    connect(m_pcmdOpcodeJNLE, SIGNAL(pressed()), pmenuCondJumpCommands, SLOT(hide()));
    connect(m_pcmdOpcodeJNLE, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeJNLE->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeJG, SIGNAL(pressed()), SLOT(makeOpcodeJG()));
    connect(m_pcmdOpcodeJG, SIGNAL(pressed()), pmenuCondJumpCommands, SLOT(hide()));
    connect(m_pcmdOpcodeJG, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeJG->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeJB, SIGNAL(pressed()), SLOT(makeOpcodeJB()));
    connect(m_pcmdOpcodeJB, SIGNAL(pressed()), pmenuCondJumpCommands, SLOT(hide()));
    connect(m_pcmdOpcodeJB, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeJB->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeJNAE, SIGNAL(pressed()), SLOT(makeOpcodeJNAE()));
    connect(m_pcmdOpcodeJNAE, SIGNAL(pressed()), pmenuCondJumpCommands, SLOT(hide()));
    connect(m_pcmdOpcodeJNAE, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeJNAE->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeJC, SIGNAL(pressed()), SLOT(makeOpcodeJC()));
    connect(m_pcmdOpcodeJC, SIGNAL(pressed()), pmenuCondJumpCommands, SLOT(hide()));
    connect(m_pcmdOpcodeJC, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeJC->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeJBE, SIGNAL(pressed()), SLOT(makeOpcodeJBE()));
    connect(m_pcmdOpcodeJBE, SIGNAL(pressed()), pmenuCondJumpCommands, SLOT(hide()));
    connect(m_pcmdOpcodeJBE, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeJBE->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeJNA, SIGNAL(pressed()), SLOT(makeOpcodeJNA()));
    connect(m_pcmdOpcodeJNA, SIGNAL(pressed()), pmenuCondJumpCommands, SLOT(hide()));
    connect(m_pcmdOpcodeJNA, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeJNA->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeJNB, SIGNAL(pressed()), SLOT(makeOpcodeJNB()));
    connect(m_pcmdOpcodeJNB, SIGNAL(pressed()), pmenuCondJumpCommands, SLOT(hide()));
    connect(m_pcmdOpcodeJNB, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeJNB->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeJAE, SIGNAL(pressed()), SLOT(makeOpcodeJAE()));
    connect(m_pcmdOpcodeJAE, SIGNAL(pressed()), pmenuCondJumpCommands, SLOT(hide()));
    connect(m_pcmdOpcodeJAE, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeJAE->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeJNC, SIGNAL(pressed()), SLOT(makeOpcodeJNC()));
    connect(m_pcmdOpcodeJNC, SIGNAL(pressed()), pmenuCondJumpCommands, SLOT(hide()));
    connect(m_pcmdOpcodeJNC, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeJNC->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeJNBE, SIGNAL(pressed()), SLOT(makeOpcodeJNBE()));
    connect(m_pcmdOpcodeJNBE, SIGNAL(pressed()), pmenuCondJumpCommands, SLOT(hide()));
    connect(m_pcmdOpcodeJNBE, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeJNBE->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeJA, SIGNAL(pressed()), SLOT(makeOpcodeJA()));
    connect(m_pcmdOpcodeJA, SIGNAL(pressed()), pmenuCondJumpCommands, SLOT(hide()));
    connect(m_pcmdOpcodeJA, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeJA->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeJE, SIGNAL(pressed()), SLOT(makeOpcodeJE()));
    connect(m_pcmdOpcodeJE, SIGNAL(pressed()), pmenuCondJumpCommands, SLOT(hide()));
    connect(m_pcmdOpcodeJE, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeJE->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeJZ, SIGNAL(pressed()), SLOT(makeOpcodeJZ()));
    connect(m_pcmdOpcodeJZ, SIGNAL(pressed()), pmenuCondJumpCommands, SLOT(hide()));
    connect(m_pcmdOpcodeJZ, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeJZ->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeJP, SIGNAL(pressed()), SLOT(makeOpcodeJP()));
    connect(m_pcmdOpcodeJP, SIGNAL(pressed()), pmenuCondJumpCommands, SLOT(hide()));
    connect(m_pcmdOpcodeJP, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeJP->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeJPE, SIGNAL(pressed()), SLOT(makeOpcodeJPE()));
    connect(m_pcmdOpcodeJPE, SIGNAL(pressed()), pmenuCondJumpCommands, SLOT(hide()));
    connect(m_pcmdOpcodeJPE, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeJPE->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeJO, SIGNAL(pressed()), SLOT(makeOpcodeJO()));
    connect(m_pcmdOpcodeJO, SIGNAL(pressed()), pmenuCondJumpCommands, SLOT(hide()));
    connect(m_pcmdOpcodeJO, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeJO->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeJS, SIGNAL(pressed()), SLOT(makeOpcodeJS()));
    connect(m_pcmdOpcodeJS, SIGNAL(pressed()), pmenuCondJumpCommands, SLOT(hide()));
    connect(m_pcmdOpcodeJS, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeJS->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeJNE, SIGNAL(pressed()), SLOT(makeOpcodeJNE()));
    connect(m_pcmdOpcodeJNE, SIGNAL(pressed()), pmenuCondJumpCommands, SLOT(hide()));
    connect(m_pcmdOpcodeJNE, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeJNE->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeJNZ, SIGNAL(pressed()), SLOT(makeOpcodeJNZ()));
    connect(m_pcmdOpcodeJNZ, SIGNAL(pressed()), pmenuCondJumpCommands, SLOT(hide()));
    connect(m_pcmdOpcodeJNZ, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeJNZ->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeJNP, SIGNAL(pressed()), SLOT(makeOpcodeJNP()));
    connect(m_pcmdOpcodeJNP, SIGNAL(pressed()), pmenuCondJumpCommands, SLOT(hide()));
    connect(m_pcmdOpcodeJNP, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeJNP->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeJPO, SIGNAL(pressed()), SLOT(makeOpcodeJPO()));
    connect(m_pcmdOpcodeJPO, SIGNAL(pressed()), pmenuCondJumpCommands, SLOT(hide()));
    connect(m_pcmdOpcodeJPO, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeJPO->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeJNO, SIGNAL(pressed()), SLOT(makeOpcodeJNO()));
    connect(m_pcmdOpcodeJNO, SIGNAL(pressed()), pmenuCondJumpCommands, SLOT(hide()));
    connect(m_pcmdOpcodeJNO, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeJNO->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeJNS, SIGNAL(pressed()), SLOT(makeOpcodeJNS()));
    connect(m_pcmdOpcodeJNS, SIGNAL(pressed()), pmenuCondJumpCommands, SLOT(hide()));
    connect(m_pcmdOpcodeJNS, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeJNS->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeJCXZ, SIGNAL(pressed()), SLOT(makeOpcodeJCXZ()));
    connect(m_pcmdOpcodeJCXZ, SIGNAL(pressed()), pmenuCondJumpCommands, SLOT(hide()));
    connect(m_pcmdOpcodeJCXZ, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeJCXZ->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeLOOP, SIGNAL(pressed()), SLOT(makeOpcodeLOOP()));
    connect(m_pcmdOpcodeLOOP, SIGNAL(pressed()), pmenuCycleManageCommands, SLOT(hide()));
    connect(m_pcmdOpcodeLOOP, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeLOOP->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeLOOPE, SIGNAL(pressed()), SLOT(makeOpcodeLOOPE()));       
    connect(m_pcmdOpcodeLOOPE, SIGNAL(pressed()), pmenuCycleManageCommands, SLOT(hide()));
    connect(m_pcmdOpcodeLOOPE, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeLOOPE->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeLOOPZ, SIGNAL(pressed()), SLOT(makeOpcodeLOOPZ()));
    connect(m_pcmdOpcodeLOOPZ, SIGNAL(pressed()), pmenuCycleManageCommands, SLOT(hide()));
    connect(m_pcmdOpcodeLOOPZ, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeLOOPZ->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeLOOPNE, SIGNAL(pressed()), SLOT(makeOpcodeLOOPNE()));
    connect(m_pcmdOpcodeLOOPNE, SIGNAL(pressed()), pmenuCycleManageCommands, SLOT(hide()));
    connect(m_pcmdOpcodeLOOPNE, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeLOOPNE->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeLOOPNZ, SIGNAL(pressed()), SLOT(makeOpcodeLOOPNZ()));
    connect(m_pcmdOpcodeLOOPNZ, SIGNAL(pressed()), pmenuCycleManageCommands, SLOT(hide()));
    connect(m_pcmdOpcodeLOOPNZ, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeLOOPNZ->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeINT, SIGNAL(pressed()), SLOT(makeOpcodeINT()));
    connect(m_pcmdOpcodeINT, SIGNAL(pressed()), pmenuInterruptCommands, SLOT(hide()));
    connect(m_pcmdOpcodeINT, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeINT->m_pleOp, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeINTO, SIGNAL(pressed()), SLOT(makeOpcodeINTO()));
    connect(m_pcmdOpcodeINTO, SIGNAL(pressed()), pmenuInterruptCommands, SLOT(hide()));
    connect(m_pcmdOpcodeINTO, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));

    connect(m_pcmdOpcodeCLC, SIGNAL(pressed()), SLOT(makeOpcodeCLC()));
    connect(m_pcmdOpcodeCLC, SIGNAL(pressed()), pmenuFlagsCommands, SLOT(hide()));
    connect(m_pcmdOpcodeCLC, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));

    connect(m_pcmdOpcodeSTC, SIGNAL(pressed()), SLOT(makeOpcodeSTC()));
    connect(m_pcmdOpcodeSTC, SIGNAL(pressed()), pmenuFlagsCommands, SLOT(hide()));
    connect(m_pcmdOpcodeSTC, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));

    connect(m_pcmdOpcodeCMC, SIGNAL(pressed()), SLOT(makeOpcodeCMC()));
    connect(m_pcmdOpcodeCMC, SIGNAL(pressed()), pmenuFlagsCommands, SLOT(hide()));
    connect(m_pcmdOpcodeCMC, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));

    connect(m_pcmdOpcodeCLD, SIGNAL(pressed()), SLOT(makeOpcodeCLD()));
    connect(m_pcmdOpcodeCLD, SIGNAL(pressed()), pmenuFlagsCommands, SLOT(hide()));
    connect(m_pcmdOpcodeCLD, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));

    connect(m_pcmdOpcodeSTD, SIGNAL(pressed()), SLOT(makeOpcodeSTD()));
    connect(m_pcmdOpcodeSTD, SIGNAL(pressed()), pmenuFlagsCommands, SLOT(hide()));
    connect(m_pcmdOpcodeSTD, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));

    connect(m_pcmdOpcodeCLI, SIGNAL(pressed()), SLOT(makeOpcodeCLI()));
    connect(m_pcmdOpcodeCLI, SIGNAL(pressed()), pmenuFlagsCommands, SLOT(hide()));
    connect(m_pcmdOpcodeCLI, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));

    connect(m_pcmdOpcodeSTI, SIGNAL(pressed()), SLOT(makeOpcodeSTI()));
    connect(m_pcmdOpcodeSTI, SIGNAL(pressed()), pmenuFlagsCommands, SLOT(hide()));
    connect(m_pcmdOpcodeSTI, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));

    connect(m_pcmdOpcodeHLT, SIGNAL(pressed()), SLOT(makeOpcodeHLT()));
    connect(m_pcmdOpcodeHLT, SIGNAL(pressed()), pmenuSpecialCommands, SLOT(hide()));
    connect(m_pcmdOpcodeHLT, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));

    connect(m_pcmdOpcodeWAIT, SIGNAL(pressed()), SLOT(makeOpcodeWAIT()));
    connect(m_pcmdOpcodeWAIT, SIGNAL(pressed()), pmenuSpecialCommands, SLOT(hide()));
    connect(m_pcmdOpcodeWAIT, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));

    connect(m_pcmdOpcodeLOCK, SIGNAL(pressed()), SLOT(makeOpcodeLOCK()));
    connect(m_pcmdOpcodeLOCK, SIGNAL(pressed()), pmenuSpecialCommands, SLOT(hide()));
    connect(m_pcmdOpcodeLOCK, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));

    connect(m_pcmdOpcodeESC, SIGNAL(pressed()), SLOT(makeOpcodeESC()));
    connect(m_pcmdOpcodeESC, SIGNAL(pressed()), pmenuSpecialCommands, SLOT(hide()));
    connect(m_pcmdOpcodeESC, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));

    connect(m_pcmdOpcodeNOP, SIGNAL(pressed()), SLOT(makeOpcodeNOP()));
    connect(m_pcmdOpcodeNOP, SIGNAL(pressed()), pmenuSpecialCommands, SLOT(hide()));
    connect(m_pcmdOpcodeNOP, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));

    /*connect(m_pcmdOpcodeRepMovs, SIGNAL(pressed()), SLOT(makeOpcodeRepMovs()));
    connect(m_pcmdOpcodeRepMovs, SIGNAL(pressed()), pmenuPrefixCommands, SLOT(hide()));
    connect(m_pcmdOpcodeRepMovs, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeRepMovs->m_pleOp2, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeRepStos, SIGNAL(pressed()), SLOT(makeOpcodeRepStos()));
    connect(m_pcmdOpcodeRepStos, SIGNAL(pressed()), pmenuPrefixCommands, SLOT(hide()));
    connect(m_pcmdOpcodeRepStos, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));

    connect(m_pcmdOpcodeRepeCmps, SIGNAL(pressed()), SLOT(makeOpcodeRepeCmps()));
    connect(m_pcmdOpcodeRepeCmps, SIGNAL(pressed()), pmenuPrefixCommands, SLOT(hide()));
    connect(m_pcmdOpcodeRepeCmps, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeRepeCmps->m_pleOp2, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeRepeScas, SIGNAL(pressed()), SLOT(makeOpcodeRepeScas()));
    connect(m_pcmdOpcodeRepeScas, SIGNAL(pressed()), pmenuPrefixCommands, SLOT(hide()));
    connect(m_pcmdOpcodeRepeScas, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeRepeScas->m_pleOp1, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeRepzCmps, SIGNAL(pressed()), SLOT(makeOpcodeRepzCmps()));
    connect(m_pcmdOpcodeRepzCmps, SIGNAL(pressed()), pmenuPrefixCommands, SLOT(hide()));
    connect(m_pcmdOpcodeRepzCmps, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeRepzCmps->m_pleOp1, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeRepzScas, SIGNAL(pressed()), SLOT(makeOpcodeRepzScas()));
    connect(m_pcmdOpcodeRepzScas, SIGNAL(pressed()), pmenuPrefixCommands, SLOT(hide()));
    connect(m_pcmdOpcodeRepzScas, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeRepzScas->m_pleOp1, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeRepneMovs, SIGNAL(pressed()), SLOT(makeOpcodeRepneMovs()));
    connect(m_pcmdOpcodeRepneMovs, SIGNAL(pressed()), pmenuPrefixCommands, SLOT(hide()));
    connect(m_pcmdOpcodeRepneMovs, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeRepneMovs->m_pleOp2, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeRepneStos, SIGNAL(pressed()), SLOT(makeOpcodeRepneStos()));
    connect(m_pcmdOpcodeRepneStos, SIGNAL(pressed()), pmenuPrefixCommands, SLOT(hide()));
    connect(m_pcmdOpcodeRepneStos, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));

    connect(m_pcmdOpcodeRepnzCmps, SIGNAL(pressed()), SLOT(makeOpcodeRepnzCmps()));
    connect(m_pcmdOpcodeRepnzCmps, SIGNAL(pressed()), pmenuPrefixCommands, SLOT(hide()));
    connect(m_pcmdOpcodeRepnzCmps, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeRepnzCmps->m_pleOp2, SIGNAL(returnPressed()), SLOT(lineAdd()));

    connect(m_pcmdOpcodeRepnzScas, SIGNAL(pressed()), SLOT(makeOpcodeRepnzScas()));
    connect(m_pcmdOpcodeRepnzScas, SIGNAL(pressed()), pmenuPrefixCommands, SLOT(hide()));
    connect(m_pcmdOpcodeRepnzScas, SIGNAL(pressed()), pmenuOpcodes, SLOT(hide()));
    connect(m_popcodeRepnzScas->m_pleOp1, SIGNAL(returnPressed()), SLOT(lineAdd()));*/


    connect(m_pcmdSaveFile, SIGNAL(clicked()), SLOT(saveFile()));
    connect(m_pcmdOpenFile, SIGNAL(clicked()), SLOT(openFile()));
    connect(m_pcmdQuit, SIGNAL(clicked()), SLOT(exitApp()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadAllPanels(void){
    QLabel* plblWelcome = new QLabel("<h1><center><strong>Спасибо за выбор OptAsm!</strong></center></h1>");
    QLabel* plblWhatNow = new QLabel("<h1><center><strong>Что дальше?</strong></center></h1>");
    m_plabelGlobal = new GLabelGlobal();
    m_plabelLocal = new GLabelLocal();
    m_plabelUnnamed = new GLabelUnnamed();
    m_pdata = new GData();
    m_pdataDup = new GDataDup();
    m_pcomment = new GComment();
    m_popcodeMOV = new GOpcodeMOV();
    m_popcodeXCHG = new GOpcodeXCHG();
    m_popcodeXLAT = new GOpcodeXLAT();
    m_popcodeLEA = new GOpcodeLEA();
    m_popcodeLDS = new GOpcodeLDS();
    m_popcodeLES = new GOpcodeLES();
    m_popcodeLAHF = new GOpcodeLAHF();
    m_popcodeSAHF = new GOpcodeSAHF();
    m_popcodePUSH = new GOpcodePUSH();
    m_popcodePOP = new GOpcodePOP();
    m_popcodePUSHF = new GOpcodePUSHF();
    m_popcodePOPF = new GOpcodePOPF();
    m_popcodeIN = new GOpcodeIN();
    m_popcodeOUT = new GOpcodeOUT();
    m_popcodeADD = new GOpcodeADD();
    m_popcodeADC = new GOpcodeADC();
    m_popcodeSUB = new GOpcodeSUB();
    m_popcodeSBB = new GOpcodeSBB();
    m_popcodeCMP = new GOpcodeCMP();
    m_popcodeMUL = new GOpcodeMUL();
    m_popcodeIMUL = new GOpcodeIMUL();
    m_popcodeDIV = new GOpcodeDIV();
    m_popcodeIDIV = new GOpcodeIDIV();
    m_popcodeINC = new GOpcodeINC();
    m_popcodeDEC = new GOpcodeDEC();
    m_popcodeNEG = new GOpcodeNEG();
    m_popcodeCBW = new GOpcodeCBW();
    m_popcodeCWD = new GOpcodeCWD();
    m_popcodeDAA = new GOpcodeDAA();
    m_popcodeDAS = new GOpcodeDAS();
    m_popcodeAAA = new GOpcodeAAA();
    m_popcodeAAS = new GOpcodeAAS();
    m_popcodeAAM = new GOpcodeAAM();
    m_popcodeAAD = new GOpcodeAAD();
    m_popcodeAND = new GOpcodeAND();
    m_popcodeOR = new GOpcodeOR();
    m_popcodeXOR = new GOpcodeXOR();
    m_popcodeNOT = new GOpcodeNOT();
    m_popcodeTEST = new GOpcodeTEST();
    m_popcodeRCL = new GOpcodeRCL();
    m_popcodeRCR = new GOpcodeRCR();
    m_popcodeROL = new GOpcodeROL();
    m_popcodeROR = new GOpcodeROR();
    m_popcodeSAL = new GOpcodeSAL();
    m_popcodeSAR = new GOpcodeSAR();
    m_popcodeSHL = new GOpcodeSHL();
    m_popcodeSHR = new GOpcodeSHR();
    m_popcodeBT = new GOpcodeBT();
    m_popcodeBTC = new GOpcodeBTC();
    m_popcodeBTR = new GOpcodeBTR();
    m_popcodeBTS = new GOpcodeBTS();
    m_popcodeJMP = new GOpcodeJMP();
    m_popcodeCALL = new GOpcodeCALL();
    m_popcodeRET = new GOpcodeRET();
    m_popcodeJL = new GOpcodeJL();
    m_popcodeJNGE = new GOpcodeJNGE();
    m_popcodeJNL = new GOpcodeJNL();
    m_popcodeJGE = new GOpcodeJGE();
    m_popcodeJLE = new GOpcodeJLE();
    m_popcodeJNG = new GOpcodeJNG();
    m_popcodeJNLE = new GOpcodeJNLE();
    m_popcodeJG = new GOpcodeJG();
    m_popcodeJB = new GOpcodeJB();
    m_popcodeJNAE = new GOpcodeJNAE();
    m_popcodeJC = new GOpcodeJC();
    m_popcodeJBE = new GOpcodeJBE();
    m_popcodeJNA = new GOpcodeJNA();
    m_popcodeJNB = new GOpcodeJNB();
    m_popcodeJAE = new GOpcodeJAE();
    m_popcodeJNC = new GOpcodeJNC();
    m_popcodeJNBE = new GOpcodeJNBE();
    m_popcodeJA = new GOpcodeJA();
    m_popcodeJE = new GOpcodeJE();
    m_popcodeJZ = new GOpcodeJZ();
    m_popcodeJP = new GOpcodeJP();
    m_popcodeJPE = new GOpcodeJPE();
    m_popcodeJO = new GOpcodeJO();
    m_popcodeJS = new GOpcodeJS();
    m_popcodeJNE = new GOpcodeJNE();
    m_popcodeJNZ = new GOpcodeJNZ();
    m_popcodeJNP = new GOpcodeJNP();
    m_popcodeJPO = new GOpcodeJPO();
    m_popcodeJNO = new GOpcodeJNO();
    m_popcodeJNS = new GOpcodeJNS();
    m_popcodeJCXZ = new GOpcodeJCXZ();
    m_popcodeLOOP = new GOpcodeLOOP();
    m_popcodeLOOPE = new GOpcodeLOOPE();
    m_popcodeLOOPZ = new GOpcodeLOOPZ();
    m_popcodeLOOPNE = new GOpcodeLOOPNE();
    m_popcodeLOOPNZ = new GOpcodeLOOPNZ();
    m_popcodeINT = new GOpcodeINT();
    m_popcodeINTO = new GOpcodeINTO();
    m_popcodeCLC = new GOpcodeCLC();
    m_popcodeSTC = new GOpcodeSTC();
    m_popcodeCMC = new GOpcodeCMC();
    m_popcodeCLD = new GOpcodeCLD();
    m_popcodeSTD = new GOpcodeSTD();
    m_popcodeCLI = new GOpcodeCLI();
    m_popcodeSTI = new GOpcodeSTI();
    m_popcodeHLT = new GOpcodeHLT();
    m_popcodeWAIT = new GOpcodeWAIT();
    m_popcodeLOCK = new GOpcodeLOCK();
    m_popcodeESC = new GOpcodeESC();
    m_popcodeNOP = new GOpcodeNOP();
//    m_popcodeRepMovs = new GOpcodeREP_MOVS();
//    m_popcodeRepStos = new GOpcodeREP_STOS();
//    m_popcodeRepeCmps = new GOpcodeREPE_CMPS();
//    m_popcodeRepeScas = new GOpcodeREPE_SCAS();
//    m_popcodeRepzCmps = new GOpcodeREPZ_CMPS();
//    m_popcodeRepzScas = new GOpcodeREPZ_SCAS();
//    m_popcodeRepneMovs = new GOpcodeREPNE_MOVS();
//    m_popcodeRepneStos = new GOpcodeREPNE_STOS();
//    m_popcodeRepnzCmps = new GOpcodeREPNZ_CMPS();
//    m_popcodeRepnzScas = new GOpcodeREPNZ_SCAS();


    m_pslContent->insertWidget(0, plblWelcome);
    m_pslContent->insertWidget(1, plblWhatNow);
    m_pslContent->insertWidget(2, m_plabelGlobal);
    m_pslContent->insertWidget(3, m_plabelLocal);
    m_pslContent->insertWidget(4, m_plabelUnnamed);
    m_pslContent->insertWidget(5, m_pdata);
    m_pslContent->insertWidget(6, m_pdataDup);
    m_pslContent->insertWidget(7, m_pcomment);
    m_pslContent->insertWidget(8, m_popcodeMOV);
    m_pslContent->insertWidget(9, m_popcodeXCHG);
    m_pslContent->insertWidget(10, m_popcodeXLAT);
    m_pslContent->insertWidget(11, m_popcodeLEA);
    m_pslContent->insertWidget(12, m_popcodeLDS);
    m_pslContent->insertWidget(13, m_popcodeLES);
    m_pslContent->insertWidget(14, m_popcodeLAHF);
    m_pslContent->insertWidget(15, m_popcodeSAHF);
    m_pslContent->insertWidget(16, m_popcodePUSH);
    m_pslContent->insertWidget(17, m_popcodePOP);
    m_pslContent->insertWidget(18, m_popcodePUSHF);
    m_pslContent->insertWidget(19, m_popcodePOPF);
    m_pslContent->insertWidget(20, m_popcodeIN);
    m_pslContent->insertWidget(21, m_popcodeOUT);
    m_pslContent->insertWidget(22, m_popcodeADD);
    m_pslContent->insertWidget(23, m_popcodeADC);
    m_pslContent->insertWidget(24, m_popcodeSUB);
    m_pslContent->insertWidget(25, m_popcodeSBB);
    m_pslContent->insertWidget(26, m_popcodeCMP);
    m_pslContent->insertWidget(27, m_popcodeMUL);
    m_pslContent->insertWidget(28, m_popcodeIMUL);
    m_pslContent->insertWidget(29, m_popcodeDIV);
    m_pslContent->insertWidget(30, m_popcodeIDIV);
    m_pslContent->insertWidget(31, m_popcodeINC);
    m_pslContent->insertWidget(32, m_popcodeDEC);
    m_pslContent->insertWidget(33, m_popcodeNEG);
    m_pslContent->insertWidget(34, m_popcodeCBW);
    m_pslContent->insertWidget(35, m_popcodeCWD);
    m_pslContent->insertWidget(36, m_popcodeDAA);
    m_pslContent->insertWidget(37, m_popcodeDAS);
    m_pslContent->insertWidget(38, m_popcodeAAA);
    m_pslContent->insertWidget(39, m_popcodeAAS);
    m_pslContent->insertWidget(40, m_popcodeAAM);
    m_pslContent->insertWidget(41, m_popcodeAAD);
    m_pslContent->insertWidget(42, m_popcodeAND);
    m_pslContent->insertWidget(43, m_popcodeOR);
    m_pslContent->insertWidget(44, m_popcodeXOR);
    m_pslContent->insertWidget(45, m_popcodeNOT);
    m_pslContent->insertWidget(46, m_popcodeTEST);
    m_pslContent->insertWidget(47, m_popcodeRCL);
    m_pslContent->insertWidget(48, m_popcodeRCR);
    m_pslContent->insertWidget(49, m_popcodeROL);
    m_pslContent->insertWidget(50, m_popcodeROR);
    m_pslContent->insertWidget(51, m_popcodeSAL);
    m_pslContent->insertWidget(52, m_popcodeSAR);
    m_pslContent->insertWidget(53, m_popcodeSHL);
    m_pslContent->insertWidget(54, m_popcodeSHR);
    m_pslContent->insertWidget(55, m_popcodeBT);
    m_pslContent->insertWidget(56, m_popcodeBTC);
    m_pslContent->insertWidget(57, m_popcodeBTR);
    m_pslContent->insertWidget(58, m_popcodeBTS);
    m_pslContent->insertWidget(59, m_popcodeJMP);
    m_pslContent->insertWidget(60, m_popcodeCALL);
    m_pslContent->insertWidget(61, m_popcodeRET);
    m_pslContent->insertWidget(62, m_popcodeJL);
    m_pslContent->insertWidget(63, m_popcodeJNGE);
    m_pslContent->insertWidget(64, m_popcodeJNL);
    m_pslContent->insertWidget(65, m_popcodeJGE);
    m_pslContent->insertWidget(66, m_popcodeJLE);
    m_pslContent->insertWidget(67, m_popcodeJNG);
    m_pslContent->insertWidget(68, m_popcodeJNLE);
    m_pslContent->insertWidget(69, m_popcodeJG);
    m_pslContent->insertWidget(70, m_popcodeJB);
    m_pslContent->insertWidget(71, m_popcodeJNAE);
    m_pslContent->insertWidget(72, m_popcodeJC);
    m_pslContent->insertWidget(73, m_popcodeJBE);
    m_pslContent->insertWidget(74, m_popcodeJNA);
    m_pslContent->insertWidget(75, m_popcodeJNB);
    m_pslContent->insertWidget(76, m_popcodeJAE);
    m_pslContent->insertWidget(77, m_popcodeJNC);
    m_pslContent->insertWidget(78, m_popcodeJNBE);
    m_pslContent->insertWidget(79, m_popcodeJA);
    m_pslContent->insertWidget(80, m_popcodeJE);
    m_pslContent->insertWidget(81, m_popcodeJZ);
    m_pslContent->insertWidget(82, m_popcodeJP);
    m_pslContent->insertWidget(83, m_popcodeJPE);
    m_pslContent->insertWidget(84, m_popcodeJO);
    m_pslContent->insertWidget(85, m_popcodeJS);
    m_pslContent->insertWidget(86, m_popcodeJNE);
    m_pslContent->insertWidget(87, m_popcodeJNZ);
    m_pslContent->insertWidget(88, m_popcodeJNP);
    m_pslContent->insertWidget(89, m_popcodeJPO);
    m_pslContent->insertWidget(90, m_popcodeJNO);
    m_pslContent->insertWidget(91, m_popcodeJNS);
    m_pslContent->insertWidget(92, m_popcodeJCXZ);
    m_pslContent->insertWidget(93, m_popcodeLOOP);
    m_pslContent->insertWidget(94, m_popcodeLOOPE);
    m_pslContent->insertWidget(95, m_popcodeLOOPZ);
    m_pslContent->insertWidget(96, m_popcodeLOOPNE);
    m_pslContent->insertWidget(97, m_popcodeLOOPNZ);
    m_pslContent->insertWidget(98, m_popcodeINT);
    m_pslContent->insertWidget(99, m_popcodeINTO);
    m_pslContent->insertWidget(100, m_popcodeCLC);
    m_pslContent->insertWidget(101, m_popcodeSTC);
    m_pslContent->insertWidget(102, m_popcodeCMC);
    m_pslContent->insertWidget(103, m_popcodeCLD);
    m_pslContent->insertWidget(104, m_popcodeSTD);
    m_pslContent->insertWidget(105, m_popcodeCLI);
    m_pslContent->insertWidget(106, m_popcodeSTI);
    m_pslContent->insertWidget(107, m_popcodeHLT);  //I'm so drunk!..
    m_pslContent->insertWidget(108, m_popcodeWAIT); //Ivan too.
    m_pslContent->insertWidget(109, m_popcodeLOCK); //Oh fuck... (29.07.2012)
    m_pslContent->insertWidget(110, m_popcodeESC);
    m_pslContent->insertWidget(111, m_popcodeNOP);
//    m_pslContent->insertWidget(112, m_popcodeRepMovs);
//    m_pslContent->insertWidget(113, m_popcodeRepStos);
//    m_pslContent->insertWidget(114, m_popcodeRepeCmps);
//    m_pslContent->insertWidget(115, m_popcodeRepeScas);
//    m_pslContent->insertWidget(116, m_popcodeRepzCmps);
//    m_pslContent->insertWidget(117, m_popcodeRepzScas);
//    m_pslContent->insertWidget(118, m_popcodeRepneMovs);
//    m_pslContent->insertWidget(119, m_popcodeRepneStos);
//    m_pslContent->insertWidget(120, m_popcodeRepnzCmps);
//    m_pslContent->insertWidget(121, m_popcodeRepnzScas);

    m_pslContent->setCurrentIndex(0);
}

void MainWindow::makeLabelGlobal(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(2);
    m_currentSSType = LABEL_GLOBAL;    
    m_plabelGlobal->setStartFocus();
}

void MainWindow::makeLabelLocal(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(3);
    m_currentSSType = LABEL_LOCAL;
    m_plabelLocal->setStartFocus();
}

void MainWindow::makeLabelUnnamed(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(4);
    m_currentSSType = LABEL_UNNAMED;
}

void MainWindow::makeDataSingle(){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(5);
    m_currentSSType = DATA_SINGLE;
    m_pdata->setStartFocus();
}

void MainWindow::makeDataDup(){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(6);
    m_currentSSType = DATA_DUP;
    m_pdataDup->setStartFocus();
}

void MainWindow::makeComment(){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(7);
    m_currentSSType = COMMENT;
    m_pcomment->setStartFocus();
}

void MainWindow::makeOpcodeMOV(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(8);
    m_currentSSType = OPCODE_MOV;
    m_popcodeMOV->setStartFocus();
}

void MainWindow::makeOpcodeXCHG(){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(9);
    m_currentSSType = OPCODE_XCHG;
    m_popcodeXCHG->setStartFocus();
}

void MainWindow::makeOpcodeXLAT(){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(10);
    m_currentSSType = OPCODE_XLAT;
}

void MainWindow::makeOpcodeLEA(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(11);
    m_currentSSType = OPCODE_LEA;
    m_popcodeLEA->setStartFocus();
}

void MainWindow::makeOpcodeLDS(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(12);
    m_currentSSType = OPCODE_LDS;
    m_popcodeLDS->setStartFocus();
}

void MainWindow::makeOpcodeLES(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(13);
    m_currentSSType = OPCODE_LES;
    m_popcodeLES->setStartFocus();
}

void MainWindow::makeOpcodeLAHF(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(14);
    m_currentSSType = OPCODE_LAHF;
}

void MainWindow::makeOpcodeSAHF(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(15);
    m_currentSSType = OPCODE_SAHF;
}

void MainWindow::makeOpcodePUSH(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(16);
    m_currentSSType = OPCODE_PUSH;
    m_popcodePUSH->setStartFocus();
}

void MainWindow::makeOpcodePOP(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(17);
    m_currentSSType = OPCODE_POP;
    m_popcodePOP->setStartFocus();
}

void MainWindow::makeOpcodePUSHF(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(18);
    m_currentSSType = OPCODE_PUSHF;
}

void MainWindow::makeOpcodePOPF(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(19);
    m_currentSSType = OPCODE_POPF;
}

void MainWindow::makeOpcodeIN(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(20);
    m_currentSSType = OPCODE_IN;
    m_popcodeIN->setStartFocus();
}

void MainWindow::makeOpcodeOUT(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(21);
    m_currentSSType = OPCODE_OUT;
    m_popcodeOUT->setStartFocus();
}

void MainWindow::makeOpcodeADD(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(22);
    m_currentSSType = OPCODE_ADD;
    m_popcodeADD->setStartFocus();
}

void MainWindow::makeOpcodeADC(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(23);
    m_currentSSType = OPCODE_ADC;
    m_popcodeADC->setStartFocus();
}

void MainWindow::makeOpcodeSUB(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(24);
    m_currentSSType = OPCODE_SUB;
    m_popcodeSUB->setStartFocus();
}

void MainWindow::makeOpcodeSBB(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(25);
    m_currentSSType = OPCODE_SBB;
    m_popcodeSBB->setStartFocus();
}

void MainWindow::makeOpcodeCMP(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(26);
    m_currentSSType = OPCODE_CMP;
    m_popcodeCMP->setStartFocus();
}

void MainWindow::makeOpcodeMUL(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(27);
    m_currentSSType = OPCODE_MUL;
    m_popcodeMUL->setStartFocus();
}

void MainWindow::makeOpcodeIMUL(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(28);
    m_currentSSType = OPCODE_IMUL;
    m_popcodeIMUL->setStartFocus();
}

void MainWindow::makeOpcodeDIV(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(29);
    m_currentSSType = OPCODE_DIV;
    m_popcodeDIV->setStartFocus();
}

void MainWindow::makeOpcodeIDIV(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(30);
    m_currentSSType = OPCODE_IDIV;
    m_popcodeIDIV->setStartFocus();
}

void MainWindow::makeOpcodeINC(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(31);
    m_currentSSType = OPCODE_INC;
    m_popcodeINC->setStartFocus();
}

void MainWindow::makeOpcodeDEC(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(32);
    m_currentSSType = OPCODE_DEC;
    m_popcodeDEC->setStartFocus();
}

void MainWindow::makeOpcodeNEG(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(33);
    m_currentSSType = OPCODE_NEG;
    m_popcodeNEG->setStartFocus();
}

void MainWindow::makeOpcodeCBW(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(34);
    m_currentSSType = OPCODE_CBW;
}

void MainWindow::makeOpcodeCWD(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(35);
    m_currentSSType = OPCODE_CWD;
}

void MainWindow::makeOpcodeDAA(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(36);
    m_currentSSType = OPCODE_DAA;
}

void MainWindow::makeOpcodeDAS(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(37);
    m_currentSSType = OPCODE_DAS;
}

void MainWindow::makeOpcodeAAA(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(38);
    m_currentSSType = OPCODE_AAA;
}

void MainWindow::makeOpcodeAAS(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(39);
    m_currentSSType = OPCODE_AAS;
}

void MainWindow::makeOpcodeAAM(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(40);
    m_currentSSType = OPCODE_AAM;
}

void MainWindow::makeOpcodeAAD(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(41);
    m_currentSSType = OPCODE_AAD;
}

void MainWindow::makeOpcodeAND(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(42);
    m_currentSSType = OPCODE_AND;
    m_popcodeAND->setStartFocus();
}

void MainWindow::makeOpcodeOR(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(43);
    m_currentSSType = OPCODE_OR;
    m_popcodeOR->setStartFocus();
}

void MainWindow::makeOpcodeXOR(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(44);
    m_currentSSType = OPCODE_XOR;
    m_popcodeXOR->setStartFocus();
}

void MainWindow::makeOpcodeNOT(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(45);
    m_currentSSType = OPCODE_NOT;
    m_popcodeNOT->setStartFocus();
}

void MainWindow::makeOpcodeTEST(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(46);
    m_currentSSType = OPCODE_TEST;
    m_popcodeTEST->setStartFocus();
}

void MainWindow::makeOpcodeRCL(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(47);
    m_currentSSType = OPCODE_RCL;
    m_popcodeRCL->setStartFocus();
}

void MainWindow::makeOpcodeRCR(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(48);
    m_currentSSType = OPCODE_RCR;
    m_popcodeRCR->setStartFocus();
}

void MainWindow::makeOpcodeROL(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(49);
    m_currentSSType = OPCODE_ROL;
    m_popcodeROL->setStartFocus();
}

void MainWindow::makeOpcodeROR(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(50);
    m_currentSSType = OPCODE_ROR;
    m_popcodeROR->setStartFocus();
}

void MainWindow::makeOpcodeSAL(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(51);
    m_currentSSType = OPCODE_SAL;
    m_popcodeSAL->setStartFocus();
}

void MainWindow::makeOpcodeSAR(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(52);
    m_currentSSType = OPCODE_SAR;
    m_popcodeSAR->setStartFocus();
}

void MainWindow::makeOpcodeSHL(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(53);
    m_currentSSType = OPCODE_SHL;
    m_popcodeSHL->setStartFocus();
}

void MainWindow::makeOpcodeSHR(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(54);
    m_currentSSType = OPCODE_SHR;
    m_popcodeSHR->setStartFocus();
}

void MainWindow::makeOpcodeBT(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(55);
    m_currentSSType = OPCODE_BT;
    m_popcodeBT->setStartFocus();
}

void MainWindow::makeOpcodeBTC(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(56);
    m_currentSSType = OPCODE_BTC;
    m_popcodeBTC->setStartFocus();
}

void MainWindow::makeOpcodeBTR(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(57);
    m_currentSSType = OPCODE_BTR;
    m_popcodeBTR->setStartFocus();
}

void MainWindow::makeOpcodeBTS(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(58);
    m_currentSSType = OPCODE_BTS;
    m_popcodeBTS->setStartFocus();
}

void MainWindow::makeOpcodeJMP(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(59);
    m_currentSSType = OPCODE_JMP;
    m_popcodeJMP->setStartFocus();
}

void MainWindow::makeOpcodeCALL(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(60);
    m_currentSSType = OPCODE_CALL;
    m_popcodeCALL->setStartFocus();
}

void MainWindow::makeOpcodeRET(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(61);
    m_currentSSType = OPCODE_RET;
    m_popcodeRET->setStartFocus();
}

void MainWindow::makeOpcodeJL(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(62);
    m_currentSSType = OPCODE_JL;
    m_popcodeJL->setStartFocus();
}

void MainWindow::makeOpcodeJNGE(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(63);
    m_currentSSType = OPCODE_JNGE;
    m_popcodeJNGE->setStartFocus();
}

void MainWindow::makeOpcodeJNL(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(64);
    m_currentSSType = OPCODE_JNL;
    m_popcodeJNL->setStartFocus();
}

void MainWindow::makeOpcodeJGE(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(65);
    m_currentSSType = OPCODE_JGE;
    m_popcodeJGE->setStartFocus();
}

void MainWindow::makeOpcodeJLE(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(66);
    m_currentSSType = OPCODE_JLE;
    m_popcodeJLE->setStartFocus();
}

void MainWindow::makeOpcodeJNG(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(67);
    m_currentSSType = OPCODE_JNG;
    m_popcodeJNG->setStartFocus();
}

void MainWindow::makeOpcodeJNLE(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(68);
    m_currentSSType = OPCODE_JNLE;
    m_popcodeJNLE->setStartFocus();
}

void MainWindow::makeOpcodeJG(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(69);
    m_currentSSType = OPCODE_JG;
    m_popcodeJG->setStartFocus();
}

void MainWindow::makeOpcodeJB(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(70);
    m_currentSSType = OPCODE_JB;
    m_popcodeJB->setStartFocus();
}

void MainWindow::makeOpcodeJNAE(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(71);
    m_currentSSType = OPCODE_JNAE;
    m_popcodeJNAE->setStartFocus();
}

void MainWindow::makeOpcodeJC(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(72);
    m_currentSSType = OPCODE_JC;
    m_popcodeJC->setStartFocus();
}

void MainWindow::makeOpcodeJBE(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(73);
    m_currentSSType = OPCODE_JBE;
    m_popcodeJBE->setStartFocus();
}

void MainWindow::makeOpcodeJNA(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(74);
    m_currentSSType = OPCODE_JNA;
    m_popcodeJNA->setStartFocus();
}

void MainWindow::makeOpcodeJNB(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(75);
    m_currentSSType = OPCODE_JNB;
    m_popcodeJNB->setStartFocus();
}

void MainWindow::makeOpcodeJAE(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(76);
    m_currentSSType = OPCODE_JAE;
    m_popcodeJAE->setStartFocus();
}

void MainWindow::makeOpcodeJNC(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(77);
    m_currentSSType = OPCODE_JNC;
    m_popcodeJNC->setStartFocus();
}

void MainWindow::makeOpcodeJNBE(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(78);
    m_currentSSType = OPCODE_JNBE;
    m_popcodeJNBE->setStartFocus();
}

void MainWindow::makeOpcodeJA(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(79);
    m_currentSSType = OPCODE_JA;
    m_popcodeJA->setStartFocus();
}

void MainWindow::makeOpcodeJE(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(80);
    m_currentSSType = OPCODE_JE;
    m_popcodeJE->setStartFocus();
}

void MainWindow::makeOpcodeJZ(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(81);
    m_currentSSType = OPCODE_JZ;
    m_popcodeJZ->setStartFocus();
}

void MainWindow::makeOpcodeJP(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(82);
    m_currentSSType = OPCODE_JP;
    m_popcodeJP->setStartFocus();
}

void MainWindow::makeOpcodeJPE(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(83);
    m_currentSSType = OPCODE_JPE;
    m_popcodeJPE->setStartFocus();
}

void MainWindow::makeOpcodeJO(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(84);
    m_currentSSType = OPCODE_JO;
    m_popcodeJO->setStartFocus();
}

void MainWindow::makeOpcodeJS(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(85);
    m_currentSSType = OPCODE_JS;
    m_popcodeJS->setStartFocus();
}

void MainWindow::makeOpcodeJNE(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(86);
    m_currentSSType = OPCODE_JNE;
    m_popcodeJNE->setStartFocus();
}

void MainWindow::makeOpcodeJNZ(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(87);
    m_currentSSType = OPCODE_JNZ;
    m_popcodeJNZ->setStartFocus();
}

void MainWindow::makeOpcodeJNP(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(88);
    m_currentSSType = OPCODE_JNP;
    m_popcodeJNP->setStartFocus();
}

void MainWindow::makeOpcodeJPO(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(89);
    m_currentSSType = OPCODE_JPO;
    m_popcodeJPO->setStartFocus();
}

void MainWindow::makeOpcodeJNO(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(90);
    m_currentSSType = OPCODE_JNO;
    m_popcodeJNO->setStartFocus();
}

void MainWindow::makeOpcodeJNS(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(91);
    m_currentSSType = OPCODE_JNS;
    m_popcodeJNS->setStartFocus();
}

void MainWindow::makeOpcodeJCXZ(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(92);
    m_currentSSType = OPCODE_JCXZ;
    m_popcodeJCXZ->setStartFocus();
}

void MainWindow::makeOpcodeLOOP(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(93);
    m_currentSSType = OPCODE_LOOP;
    m_popcodeLOOP->setStartFocus();
}

void MainWindow::makeOpcodeLOOPE(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(94);
    m_currentSSType = OPCODE_LOOPE;
    m_popcodeLOOPE->setStartFocus();
}

void MainWindow::makeOpcodeLOOPZ(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(95);
    m_currentSSType = OPCODE_LOOPZ;
    m_popcodeLOOPZ->setStartFocus();
}

void MainWindow::makeOpcodeLOOPNE(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(96);
    m_currentSSType = OPCODE_LOOPNE;
    m_popcodeLOOPNE->setStartFocus();
}

void MainWindow::makeOpcodeLOOPNZ(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(97);
    m_currentSSType = OPCODE_LOOPNZ;
    m_popcodeLOOPNZ->setStartFocus();
}

void MainWindow::makeOpcodeINT(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(98);
    m_currentSSType = OPCODE_INT;
    m_popcodeINT->setStartFocus();
}

void MainWindow::makeOpcodeINTO(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(99);
    m_currentSSType = OPCODE_INTO;

}

void MainWindow::makeOpcodeCLC(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(100);
    m_currentSSType = OPCODE_CLC;
}

void MainWindow::makeOpcodeSTC(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(101);
    m_currentSSType = OPCODE_STC;
}

void MainWindow::makeOpcodeCMC(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(102);
    m_currentSSType = OPCODE_CMC;
}

void MainWindow::makeOpcodeCLD(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(103);
    m_currentSSType = OPCODE_CLD;
}

void MainWindow::makeOpcodeSTD(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(104);
    m_currentSSType = OPCODE_STD;
}

void MainWindow::makeOpcodeCLI(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(105);
    m_currentSSType = OPCODE_CLI;
}

void MainWindow::makeOpcodeSTI(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(106);
    m_currentSSType = OPCODE_STI;
}

void MainWindow::makeOpcodeHLT(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(107);
    m_currentSSType = OPCODE_HLT;
}

void MainWindow::makeOpcodeWAIT(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(108);
    m_currentSSType = OPCODE_WAIT;
}

void MainWindow::makeOpcodeLOCK(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(109);
    m_currentSSType = OPCODE_LOCK;
}

void MainWindow::makeOpcodeESC(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(110);
    m_currentSSType = OPCODE_ESC;
}

void MainWindow::makeOpcodeNOP(void){

    m_pcmdAddString->setEnabled(true);
    m_pcmdCancel->setEnabled(true);
    m_pslContent->setCurrentIndex(111);
    m_currentSSType = OPCODE_NOP;
}

//void MainWindow::makeOpcodeRepMovs(void){

//    m_pcmdAddString->setEnabled(true);
//    m_pcmdCancel->setEnabled(true);
//    m_pslContent->setCurrentIndex(112);
//    m_currentSSType = OPCODE_REP_MOVS;
//    m_popcodeRepMovs->setStartFocus();
//}

//void MainWindow::makeOpcodeRepStos(void){

//    m_pcmdAddString->setEnabled(true);
//    m_pcmdCancel->setEnabled(true);
//    m_pslContent->setCurrentIndex(113);
//    m_currentSSType = OPCODE_REP_STOS;
//}

//void MainWindow::makeOpcodeRepeCmps(void){

//    m_pcmdAddString->setEnabled(true);
//    m_pcmdCancel->setEnabled(true);
//    m_pslContent->setCurrentIndex(114);
//    m_currentSSType = OPCODE_REPE_CMPS;
//    m_popcodeRepeCmps->setStartFocus();
//}

//void MainWindow::makeOpcodeRepeScas(void){

//    m_pcmdAddString->setEnabled(true);
//    m_pcmdCancel->setEnabled(true);
//    m_pslContent->setCurrentIndex(115);
//    m_currentSSType = OPCODE_REPE_SCAS;
//    m_popcodeRepeScas->setStartFocus();
//}

//void MainWindow::makeOpcodeRepzCmps(void){

//    m_pcmdAddString->setEnabled(true);
//    m_pcmdCancel->setEnabled(true);
//    m_pslContent->setCurrentIndex(116);
//    m_currentSSType = OPCODE_REPZ_CMPS;
//    m_popcodeRepzCmps->setStartFocus();
//}

//void MainWindow::makeOpcodeRepzScas(void){

//    m_pcmdAddString->setEnabled(true);
//    m_pcmdCancel->setEnabled(true);
//    m_pslContent->setCurrentIndex(117);
//    m_currentSSType = OPCODE_REPZ_SCAS;
//    m_popcodeRepzScas->setStartFocus();
//}

//void MainWindow::makeOpcodeRepneMovs(void){

//    m_pcmdAddString->setEnabled(true);
//    m_pcmdCancel->setEnabled(true);
//    m_pslContent->setCurrentIndex(118);
//    m_currentSSType = OPCODE_REPNE_MOVS;
//    m_popcodeRepneMovs->setStartFocus();
//}

//void MainWindow::makeOpcodeRepneStos(void){

//    m_pcmdAddString->setEnabled(true);
//    m_pcmdCancel->setEnabled(true);
//    m_pslContent->setCurrentIndex(119);
//    m_currentSSType = OPCODE_REPNE_STOS;
//}

//void MainWindow::makeOpcodeRepnzCmps(void){

//    m_pcmdAddString->setEnabled(true);
//    m_pcmdCancel->setEnabled(true);
//    m_pslContent->setCurrentIndex(120);
//    m_currentSSType = OPCODE_REPNZ_CMPS;
//    m_popcodeRepnzCmps->setStartFocus();
//}

//void MainWindow::makeOpcodeRepnzScas(void){

//    m_pcmdAddString->setEnabled(true);
//    m_pcmdCancel->setEnabled(true);
//    m_pslContent->setCurrentIndex(121);
//    m_currentSSType = OPCODE_REPNZ_SCAS;
//    m_popcodeRepnzScas->setStartFocus();
//}

void MainWindow::lineUp(void){
    if(m_nNumberOfLine <= 899){
        this->m_plcdNumberOfLine->display(++m_nNumberOfLine);
        m_pcmdLineDown->setEnabled(true);

        if(m_nNumberOfLine == 900){
            m_pcmdLineUp->setEnabled(false);
        }
    }
}

void MainWindow::lineDown(void){
    if(m_nNumberOfLine >= 2){
        this->m_plcdNumberOfLine->display(--m_nNumberOfLine);
        m_pcmdLineUp->setEnabled(true);

        if(m_nNumberOfLine == 1){
            m_pcmdLineDown->setEnabled(false);
        }
    }
}

void MainWindow::lineAdd(void){

    GSourceString* psourceStr;
    m_pcmdAddString->setEnabled(false);
    m_pcmdCancel->setEnabled(false);

    switch(m_currentSSType){
    case LABEL_GLOBAL:
        m_plabelGlobal->saveData();
        psourceStr = new GSourceString(m_plabelGlobal, m_nNumberOfLine);
        m_plabelGlobal->clearSource();
        break;

    case LABEL_LOCAL:
        m_plabelLocal->saveData();
        psourceStr = new GSourceString(m_plabelLocal, m_nNumberOfLine);
        m_plabelLocal->clearSource();
        break;

    case LABEL_UNNAMED:
        psourceStr = new GSourceString(m_plabelUnnamed, m_nNumberOfLine);
        break;
    case DATA_SINGLE:
        m_pdata->saveData();
        psourceStr = new GSourceString(m_pdata, m_nNumberOfLine);
        m_pdata->clearSource();
        break;
    case DATA_DUP:
        m_pdataDup->saveData();
        psourceStr = new GSourceString(m_pdataDup, m_nNumberOfLine);
        m_pdataDup->clearSource();
        break;
    case COMMENT:
        m_pcomment->saveData();
        psourceStr = new GSourceString(m_pcomment, m_nNumberOfLine);
        m_pcomment->clearSource();
        break;
    case OPCODE_MOV:
        m_popcodeMOV->saveData();
        psourceStr = new GSourceString(m_popcodeMOV, m_nNumberOfLine);
        m_popcodeMOV->clearSource();        
        break;
    case OPCODE_XCHG:
        m_popcodeXCHG->saveData();
        psourceStr = new GSourceString(m_popcodeXCHG, m_nNumberOfLine);
        m_popcodeXCHG->clearSource();
        break;
    case OPCODE_XLAT:
        psourceStr = new GSourceString(m_popcodeXLAT, m_nNumberOfLine);
        break;
    case OPCODE_LEA:
        m_popcodeLEA->saveData();
        psourceStr = new GSourceString(m_popcodeLEA, m_nNumberOfLine);
        m_popcodeLEA->clearSource();
        break;
    case OPCODE_LDS:
        m_popcodeLDS->saveData();
        psourceStr = new GSourceString(m_popcodeLDS, m_nNumberOfLine);
        m_popcodeLDS->clearSource();
        break;
    case OPCODE_LES:
        m_popcodeLES->saveData();
        psourceStr = new GSourceString(m_popcodeLES, m_nNumberOfLine);
        m_popcodeLES->clearSource();
        break;
    case OPCODE_LAHF:
        psourceStr = new GSourceString(m_popcodeLAHF, m_nNumberOfLine);
        break;
    case OPCODE_SAHF:
        psourceStr = new GSourceString(m_popcodeSAHF, m_nNumberOfLine);
        break;
    case OPCODE_PUSH:
        m_popcodePUSH->saveData();
        psourceStr = new GSourceString(m_popcodePUSH, m_nNumberOfLine);
        m_popcodePUSH->clearSource();
        break;
    case OPCODE_POP:
        m_popcodePOP->saveData();
        psourceStr = new GSourceString(m_popcodePOP, m_nNumberOfLine);
        m_popcodePOP->clearSource();
        break;
    case OPCODE_PUSHF:
        psourceStr = new GSourceString(m_popcodePUSHF, m_nNumberOfLine);
        break;
    case OPCODE_POPF:
        psourceStr = new GSourceString(m_popcodePOPF, m_nNumberOfLine);
        break;
    case OPCODE_IN:
        m_popcodeIN->saveData();
        psourceStr = new GSourceString(m_popcodeIN, m_nNumberOfLine);
        m_popcodeIN->clearSource();
        break;
    case OPCODE_OUT:
        m_popcodeOUT->saveData();
        psourceStr = new GSourceString(m_popcodeOUT, m_nNumberOfLine);
        m_popcodeOUT->clearSource();
        break;
    case OPCODE_ADD:
        m_popcodeADD->saveData();
        psourceStr = new GSourceString(m_popcodeADD, m_nNumberOfLine);
        m_popcodeADD->clearSource();
        break;
    case OPCODE_ADC:
        m_popcodeADC->saveData();
        psourceStr = new GSourceString(m_popcodeADC, m_nNumberOfLine);
        m_popcodeADC->clearSource();
        break;
    case OPCODE_SUB:
        m_popcodeSUB->saveData();
        psourceStr = new GSourceString(m_popcodeSUB, m_nNumberOfLine);
        m_popcodeSUB->clearSource();
        break;
    case OPCODE_SBB:
        m_popcodeSBB->saveData();
        psourceStr = new GSourceString(m_popcodeSBB, m_nNumberOfLine);
        m_popcodeSBB->clearSource();
        break;
    case OPCODE_CMP:
        m_popcodeCMP->saveData();
        psourceStr = new GSourceString(m_popcodeCMP, m_nNumberOfLine);
        m_popcodeCMP->clearSource();
        break;
    case OPCODE_MUL:
        m_popcodeMUL->saveData();
        psourceStr = new GSourceString(m_popcodeMUL, m_nNumberOfLine);
        m_popcodeMUL->clearSource();
        break;
    case OPCODE_IMUL:
        m_popcodeIMUL->saveData();
        psourceStr = new GSourceString(m_popcodeIMUL, m_nNumberOfLine);
        m_popcodeIMUL->clearSource();
        break;
    case OPCODE_DIV:
        m_popcodeDIV->saveData();
        psourceStr = new GSourceString(m_popcodeDIV, m_nNumberOfLine);
        m_popcodeDIV->clearSource();
        break;
    case OPCODE_IDIV:
        m_popcodeIDIV->saveData();
        psourceStr = new GSourceString(m_popcodeIDIV, m_nNumberOfLine);
        m_popcodeIDIV->clearSource();
        break;
    case OPCODE_INC:
        m_popcodeINC->saveData();
        psourceStr = new GSourceString(m_popcodeINC, m_nNumberOfLine);
        m_popcodeINC->clearSource();
        break;
    case OPCODE_DEC:
        m_popcodeDEC->saveData();
        psourceStr = new GSourceString(m_popcodeDEC, m_nNumberOfLine);
        m_popcodeDEC->clearSource();
        break;
    case OPCODE_NEG:
        m_popcodeNEG->saveData();
        psourceStr = new GSourceString(m_popcodeNEG, m_nNumberOfLine);
        m_popcodeNEG->clearSource();
        break;
    case OPCODE_CBW:
        psourceStr = new GSourceString(m_popcodeCBW, m_nNumberOfLine);
        break;
    case OPCODE_CWD:
        psourceStr = new GSourceString(m_popcodeCWD, m_nNumberOfLine);
        break;
    case OPCODE_DAA:
        psourceStr = new GSourceString(m_popcodeDAA, m_nNumberOfLine);
        break;
    case OPCODE_DAS:
        psourceStr = new GSourceString(m_popcodeDAS, m_nNumberOfLine);
        break;
    case OPCODE_AAA:
        psourceStr = new GSourceString(m_popcodeAAA, m_nNumberOfLine);
        break;
    case OPCODE_AAS:
        psourceStr = new GSourceString(m_popcodeAAS, m_nNumberOfLine);
        break;
    case OPCODE_AAM:
        psourceStr = new GSourceString(m_popcodeAAM, m_nNumberOfLine);
        break;
    case OPCODE_AAD:
        psourceStr = new GSourceString(m_popcodeAAD, m_nNumberOfLine);
        break;
    case OPCODE_AND:
        m_popcodeAND->saveData();
        psourceStr = new GSourceString(m_popcodeAND, m_nNumberOfLine);
        m_popcodeAND->clearSource();
        break;
    case OPCODE_OR:
        m_popcodeOR->saveData();
        psourceStr = new GSourceString(m_popcodeOR, m_nNumberOfLine);
        m_popcodeOR->clearSource();
        break;
    case OPCODE_XOR:
        m_popcodeXOR->saveData();
        psourceStr = new GSourceString(m_popcodeXOR, m_nNumberOfLine);
        m_popcodeXOR->clearSource();
        break;
    case OPCODE_NOT:
        m_popcodeNOT->saveData();
        psourceStr = new GSourceString(m_popcodeNOT, m_nNumberOfLine);
        m_popcodeNOT->clearSource();
        break;
    case OPCODE_TEST:
        m_popcodeTEST->saveData();
        psourceStr = new GSourceString(m_popcodeTEST, m_nNumberOfLine);
        m_popcodeTEST->clearSource();
        break;
    case OPCODE_RCL:
        m_popcodeRCL->saveData();
        psourceStr = new GSourceString(m_popcodeRCL, m_nNumberOfLine);
        m_popcodeRCL->clearSource();
        break;
    case OPCODE_RCR:
        m_popcodeRCR->saveData();
        psourceStr = new GSourceString(m_popcodeRCR, m_nNumberOfLine);
        m_popcodeRCR->clearSource();
        break;
    case OPCODE_ROL:
        m_popcodeROL->saveData();
        psourceStr = new GSourceString(m_popcodeROL, m_nNumberOfLine);
        m_popcodeROL->clearSource();
        break;
    case OPCODE_ROR:
        m_popcodeROR->saveData();
        psourceStr = new GSourceString(m_popcodeROR, m_nNumberOfLine);
        m_popcodeROR->clearSource();
        break;
    case OPCODE_SAL:
        m_popcodeSAL->saveData();
        psourceStr = new GSourceString(m_popcodeSAL, m_nNumberOfLine);
        m_popcodeSAL->clearSource();
        break;
    case OPCODE_SAR:
        m_popcodeSAR->saveData();
        psourceStr = new GSourceString(m_popcodeSAR, m_nNumberOfLine);
        m_popcodeSAR->clearSource();
        break;
    case OPCODE_SHL:
        m_popcodeSHL->saveData();
        psourceStr = new GSourceString(m_popcodeSHL, m_nNumberOfLine);
        m_popcodeSHL->clearSource();
        break;
    case OPCODE_SHR:
        m_popcodeSHR->saveData();
        psourceStr = new GSourceString(m_popcodeSHR, m_nNumberOfLine);
        m_popcodeSHR->clearSource();
        break;
    case OPCODE_BT:
        m_popcodeBT->saveData();
        psourceStr = new GSourceString(m_popcodeBT, m_nNumberOfLine);
        m_popcodeBT->clearSource();
        break;
    case OPCODE_BTC:
        m_popcodeBTC->saveData();
        psourceStr = new GSourceString(m_popcodeBTC, m_nNumberOfLine);
        m_popcodeBTC->clearSource();
        break;
    case OPCODE_BTR:
        m_popcodeBTR->saveData();
        psourceStr = new GSourceString(m_popcodeBTR, m_nNumberOfLine);
        m_popcodeBTR->clearSource();
        break;
    case OPCODE_BTS:
        m_popcodeBTS->saveData();
        psourceStr = new GSourceString(m_popcodeBTS, m_nNumberOfLine);
        m_popcodeBTS->clearSource();
        break;
    case OPCODE_JMP:
        m_popcodeJMP->saveData();
        psourceStr = new GSourceString(m_popcodeJMP, m_nNumberOfLine);
        m_popcodeJMP->clearSource();
        break;
    case OPCODE_CALL:
        m_popcodeCALL->saveData();
        psourceStr = new GSourceString(m_popcodeCALL, m_nNumberOfLine);
        m_popcodeCALL->clearSource();
        break;
    case OPCODE_RET:
        m_popcodeRET->saveData();
        psourceStr = new GSourceString(m_popcodeRET, m_nNumberOfLine);
        m_popcodeRET->clearSource();
        break;
    case OPCODE_JL:
        m_popcodeJL->saveData();
        psourceStr = new GSourceString(m_popcodeJL, m_nNumberOfLine);
        m_popcodeJL->clearSource();
        break;
    case OPCODE_JNGE:
        m_popcodeJNGE->saveData();
        psourceStr = new GSourceString(m_popcodeJNGE, m_nNumberOfLine);
        m_popcodeJNGE->clearSource();
        break;
    case OPCODE_JNL:
        m_popcodeJNL->saveData();
        psourceStr = new GSourceString(m_popcodeJNL, m_nNumberOfLine);
        m_popcodeJNL->clearSource();
        break;
    case OPCODE_JGE:
        m_popcodeJGE->saveData();
        psourceStr = new GSourceString(m_popcodeJGE, m_nNumberOfLine);
        m_popcodeJGE->clearSource();
        break;
    case OPCODE_JLE:
        m_popcodeJLE->saveData();
        psourceStr = new GSourceString(m_popcodeJLE, m_nNumberOfLine);
        m_popcodeJLE->clearSource();
        break;
    case OPCODE_JNG:
        m_popcodeJNG->saveData();
        psourceStr = new GSourceString(m_popcodeJNG, m_nNumberOfLine);
        m_popcodeJNG->clearSource();
        break;
    case OPCODE_JNLE:
        m_popcodeJNLE->saveData();
        psourceStr = new GSourceString(m_popcodeJNLE, m_nNumberOfLine);
        m_popcodeJNLE->clearSource();
        break;
    case OPCODE_JG:
        m_popcodeJG->saveData();
        psourceStr = new GSourceString(m_popcodeJG, m_nNumberOfLine);
        m_popcodeJG->clearSource();
        break;
    case OPCODE_JB:
        m_popcodeJB->saveData();
        psourceStr = new GSourceString(m_popcodeJB, m_nNumberOfLine);
        m_popcodeJB->clearSource();
        break;
    case OPCODE_JNAE:
        m_popcodeJNAE->saveData();
        psourceStr = new GSourceString(m_popcodeJNAE, m_nNumberOfLine);
        m_popcodeJNAE->clearSource();
        break;
    case OPCODE_JC:
        m_popcodeJC->saveData();
        psourceStr = new GSourceString(m_popcodeJC, m_nNumberOfLine);
        m_popcodeJC->clearSource();
        break;
    case OPCODE_JBE:
        m_popcodeJBE->saveData();
        psourceStr = new GSourceString(m_popcodeJBE, m_nNumberOfLine);
        m_popcodeJBE->clearSource();
        break;
    case OPCODE_JNA:
        m_popcodeJNA->saveData();
        psourceStr = new GSourceString(m_popcodeJNA, m_nNumberOfLine);
        m_popcodeJNA->clearSource();
        break;
    case OPCODE_JNB:
        m_popcodeJNB->saveData();
        psourceStr = new GSourceString(m_popcodeJNB, m_nNumberOfLine);
        m_popcodeJNB->clearSource();
        break;
    case OPCODE_JAE:
        m_popcodeJAE->saveData();
        psourceStr = new GSourceString(m_popcodeJAE, m_nNumberOfLine);
        m_popcodeJAE->clearSource();
        break;
    case OPCODE_JNC:
        m_popcodeJNC->saveData();
        psourceStr = new GSourceString(m_popcodeJNC, m_nNumberOfLine);
        m_popcodeJNC->clearSource();
        break;
    case OPCODE_JNBE:
        m_popcodeJNBE->saveData();
        psourceStr = new GSourceString(m_popcodeJNBE, m_nNumberOfLine);
        m_popcodeJNBE->clearSource();
        break;
    case OPCODE_JA:
        m_popcodeJA->saveData();
        psourceStr = new GSourceString(m_popcodeJA, m_nNumberOfLine);
        m_popcodeJA->clearSource();
        break;
    case OPCODE_JE:
        m_popcodeJE->saveData();
        psourceStr = new GSourceString(m_popcodeJE, m_nNumberOfLine);
        m_popcodeJE->clearSource();
        break;
    case OPCODE_JZ:
        m_popcodeJZ->saveData();
        psourceStr = new GSourceString(m_popcodeJZ, m_nNumberOfLine);
        m_popcodeJZ->clearSource();
        break;
    case OPCODE_JP:
        m_popcodeJP->saveData();
        psourceStr = new GSourceString(m_popcodeJP, m_nNumberOfLine);
        m_popcodeJP->clearSource();
        break;
    case OPCODE_JPE:
        m_popcodeJPE->saveData();
        psourceStr = new GSourceString(m_popcodeJPE, m_nNumberOfLine);
        m_popcodeJPE->clearSource();
        break;
    case OPCODE_JO:
        m_popcodeJO->saveData();
        psourceStr = new GSourceString(m_popcodeJO, m_nNumberOfLine);
        m_popcodeJO->clearSource();
        break;
    case OPCODE_JS:
        m_popcodeJS->saveData();
        psourceStr = new GSourceString(m_popcodeJS, m_nNumberOfLine);
        m_popcodeJS->clearSource();
        break;
    case OPCODE_JNE:
        m_popcodeJNE->saveData();
        psourceStr = new GSourceString(m_popcodeJNE, m_nNumberOfLine);
        m_popcodeJNE->clearSource();
        break;
    case OPCODE_JNZ:
        m_popcodeJNZ->saveData();
        psourceStr = new GSourceString(m_popcodeJNZ, m_nNumberOfLine);
        m_popcodeJNZ->clearSource();
        break;
    case OPCODE_JNP:
        m_popcodeJNP->saveData();
        psourceStr = new GSourceString(m_popcodeJNP, m_nNumberOfLine);
        m_popcodeJNP->clearSource();
        break;
    case OPCODE_JPO:
        m_popcodeJPO->saveData();
        psourceStr = new GSourceString(m_popcodeJPO, m_nNumberOfLine);
        m_popcodeJPO->clearSource();
        break;
    case OPCODE_JNO:
        m_popcodeJNO->saveData();
        psourceStr = new GSourceString(m_popcodeJNO, m_nNumberOfLine);
        m_popcodeJNO->clearSource();
        break;
    case OPCODE_JNS:
        m_popcodeJNS->saveData();
        psourceStr = new GSourceString(m_popcodeJNS, m_nNumberOfLine);
        m_popcodeJNS->clearSource();
        break;
    case OPCODE_JCXZ:
        m_popcodeJCXZ->saveData();
        psourceStr = new GSourceString(m_popcodeJCXZ, m_nNumberOfLine);
        m_popcodeJCXZ->clearSource();
        break;
    case OPCODE_LOOP:
        m_popcodeLOOP->saveData();
        psourceStr = new GSourceString(m_popcodeLOOP, m_nNumberOfLine);
        m_popcodeLOOP->clearSource();
        break;
    case OPCODE_LOOPE:
        m_popcodeLOOPE->saveData();
        psourceStr = new GSourceString(m_popcodeLOOPE, m_nNumberOfLine);
        m_popcodeLOOPE->clearSource();
        break;
    case OPCODE_LOOPZ:
        m_popcodeLOOPZ->saveData();
        psourceStr = new GSourceString(m_popcodeLOOPZ, m_nNumberOfLine);
        m_popcodeLOOPZ->clearSource();
        break;
    case OPCODE_LOOPNE:
        m_popcodeLOOPNE->saveData();
        psourceStr = new GSourceString(m_popcodeLOOPNE, m_nNumberOfLine);
        m_popcodeLOOPNE->clearSource();
        break;
    case OPCODE_LOOPNZ:
        m_popcodeLOOPNZ->saveData();
        psourceStr = new GSourceString(m_popcodeLOOPNZ, m_nNumberOfLine);
        m_popcodeLOOPNZ->clearSource();
        break;
    case OPCODE_INT:
        m_popcodeINT->saveData();
        psourceStr = new GSourceString(m_popcodeINT, m_nNumberOfLine);
        m_popcodeINT->clearSource();
        break;
    case OPCODE_INTO:        
        psourceStr = new GSourceString(m_popcodeINTO, m_nNumberOfLine);
        break;
    case OPCODE_CLC:
        psourceStr = new GSourceString(m_popcodeCLC, m_nNumberOfLine);
        break;
    case OPCODE_STC:
        psourceStr = new GSourceString(m_popcodeSTC, m_nNumberOfLine);
        break;
    case OPCODE_CMC:
        psourceStr = new GSourceString(m_popcodeCMC, m_nNumberOfLine);
        break;
    case OPCODE_CLD:
        psourceStr = new GSourceString(m_popcodeCLD, m_nNumberOfLine);
        break;
    case OPCODE_STD:
        psourceStr = new GSourceString(m_popcodeSTD, m_nNumberOfLine);
        break;
    case OPCODE_CLI:
        psourceStr = new GSourceString(m_popcodeCLI, m_nNumberOfLine);
        break;
    case OPCODE_STI:
        psourceStr = new GSourceString(m_popcodeSTI, m_nNumberOfLine);
        break;
    case OPCODE_HLT:
        psourceStr = new GSourceString(m_popcodeHLT, m_nNumberOfLine);
        break;
    case OPCODE_WAIT:
        psourceStr = new GSourceString(m_popcodeWAIT, m_nNumberOfLine);
        break;
    case OPCODE_LOCK:
        psourceStr = new GSourceString(m_popcodeLOCK, m_nNumberOfLine);
        break;
    case OPCODE_ESC:
        psourceStr = new GSourceString(m_popcodeESC, m_nNumberOfLine);
        break;
    case OPCODE_NOP:
        psourceStr = new GSourceString(m_popcodeNOP, m_nNumberOfLine);
        break;
//    case OPCODE_REP_MOVS:
//        m_popcodeRepMovs->saveData();
//        psourceStr = new GSourceString(m_popcodeRepMovs, m_nNumberOfLine);
//        m_popcodeRepMovs->clearSource();
//        break;
//    case OPCODE_REP_STOS:
//        psourceStr = new GSourceString(m_popcodeRepStos, m_nNumberOfLine);
//        break;
//    case OPCODE_REPE_CMPS:
//        m_popcodeRepeCmps->saveData();
//        psourceStr = new GSourceString(m_popcodeRepeCmps, m_nNumberOfLine);
//        m_popcodeRepeCmps->clearSource();
//        break;
//    case OPCODE_REPE_SCAS:
//        m_popcodeRepeScas->saveData();
//        psourceStr = new GSourceString(m_popcodeRepeScas, m_nNumberOfLine);
//        m_popcodeRepeScas->clearSource();
//        break;
//    case OPCODE_REPZ_CMPS:
//        m_popcodeRepzCmps->saveData();
//        psourceStr = new GSourceString(m_popcodeRepzCmps, m_nNumberOfLine);
//        m_popcodeRepzCmps->clearSource();
//        break;
//    case OPCODE_REPZ_SCAS:
//        m_popcodeRepzScas->saveData();
//        psourceStr = new GSourceString(m_popcodeRepzScas, m_nNumberOfLine);
//        m_popcodeRepzScas->clearSource();
//        break;
//    case OPCODE_REPNE_MOVS:
//        m_popcodeRepneMovs->saveData();
//        psourceStr = new GSourceString(m_popcodeRepneMovs, m_nNumberOfLine);
//        m_popcodeRepneMovs->clearSource();
//        break;
//    case OPCODE_REPNE_STOS:
//        psourceStr = new GSourceString(m_popcodeRepneStos, m_nNumberOfLine);
//        break;
//    case OPCODE_REPNZ_CMPS:
//        m_popcodeRepnzCmps->saveData();
//        psourceStr = new GSourceString(m_popcodeRepnzCmps, m_nNumberOfLine);
//        m_popcodeRepnzCmps->clearSource();
//        break;
//    case OPCODE_REPNZ_SCAS:
//        m_popcodeRepnzScas->saveData();
//        psourceStr = new GSourceString(m_popcodeRepnzScas, m_nNumberOfLine);
//        m_popcodeRepnzScas->clearSource();
//        break;
    }

    m_ptheCode->addString(psourceStr);

    //refresh terminal
    m_pteSource->clear();
    QStringList* strlstTEMP = m_ptheCode->getStringList();
    QStringList::iterator it;

    for(it = strlstTEMP->begin(); it != strlstTEMP->end(); ++it){
        m_pteSource->append(*it);
    }

    m_nNumberOfLine = strlstTEMP->count() + 1;
    m_plcdNumberOfLine->display(m_nNumberOfLine);
    if(m_nNumberOfLine != 1){
        m_pcmdLineDown->setEnabled(true);
    }       

    loadAllPanels();    
    //lineUp();
}

void MainWindow::lineCancel(void){
    m_pslContent->setCurrentIndex(1);
    m_pcmdAddString->setEnabled(false);
    m_pcmdCancel->setEnabled(false);
}

void MainWindow::saveFile(void){
    QString strCode = m_pteSource->toPlainText();
    QStringList str_lst = strCode.split("\n");
    QString strComplete;

    foreach(QString str, str_lst){
        strComplete.append(str);
        strComplete.append("\n");
    }

    QString filename = QFileDialog::getSaveFileName(this, "Сохранить файл", QDir::currentPath(), "Assembler source (*.asm)");
    QFile file(filename);

    if(file.open(QIODevice::WriteOnly)){
        QTextStream out(&file);
        out << strComplete.toUtf8();

       file.close();

       if(out.status() != QTextStream::Ok){
           QMessageBox::warning(this, "OptAsm v1.0", "Ошибка сохранения");
       }
    }
}

void MainWindow::openFile(void){
    QString filename = QFileDialog::getOpenFileName(this, "Открыть файл", QDir::currentPath(), "Assembler source (*.asm)");
    QFile file(filename);
    if(file.open(QIODevice::ReadWrite)){
        QTextStream in(&file);
        QString strCodeLine;
        QStringList lstOpcode;
        QString opcodeName;
        QString oper1;
        QString oper2;

        QRegExp global_label_regex = QRegExp("^\\w+:$");
        QRegExp local_label_regex = QRegExp("^\\.\\w+:$");
        QRegExp unnamed_label_regex = QRegExp("^@@:$");
        QRegExp comment_regex = QRegExp("^;.+$");
        QRegExp single_data_regex = QRegExp("^\\w+\\s+(db|dw|du|dd|df|dp|dq|dt)\\s+.+$");
        QRegExp dup_data_regex = QRegExp("^\\w+\\s+(db|dw|du|dd|df|dp|dq|dt)\\s+\\d+\\s+dup\\s+\\(.+\\)$");

        int nLineNum(0);
        while(!in.atEnd()){
            ++nLineNum;
            strCodeLine = in.readLine();
            m_pteSource->append(strCodeLine);
            strCodeLine = strCodeLine.trimmed();
            lstOpcode = strCodeLine.split(" ");
            GSourceString* psrcStr;
            //opcodeName = lstOpcode.at(0);                        


            if (strCodeLine.contains(global_label_regex)) {

                //поиск глобальных меток
                strCodeLine = strCodeLine.remove(strCodeLine.length()-1, 1);
                GLabelGlobal* plabelGlobal = new GLabelGlobal(strCodeLine);
                psrcStr = new GSourceString(plabelGlobal, nLineNum);
            }
            else if (strCodeLine.contains(local_label_regex)) {

                //поиск локальных меток
                strCodeLine = strCodeLine.remove(strCodeLine.length()-1, 1);
                strCodeLine = strCodeLine.remove(0, 1);
                GLabelLocal* plabelLocal = new GLabelLocal(strCodeLine);
                psrcStr = new GSourceString(plabelLocal, nLineNum);
            }
            else if (strCodeLine.contains(unnamed_label_regex)) {

                //поиск безымянных меток
                GLabelUnnamed* plabelUnnamed = new GLabelUnnamed();
                psrcStr = new GSourceString(plabelUnnamed, nLineNum);
            }
            else if (strCodeLine.contains(comment_regex)) {

                //поиск комментария
                strCodeLine = strCodeLine.remove(0, 1);
                GComment* pcomment = new GComment(strCodeLine);
                psrcStr = new GSourceString(pcomment, nLineNum);
            }
            else if (strCodeLine.contains(dup_data_regex)) {

              QString data_name = lstOpcode.at(0);
              QString data_type = lstOpcode.at(1);
              QString dup_value = lstOpcode.at(2);
              lstOpcode.removeFirst();
              lstOpcode.removeFirst();
              lstOpcode.removeFirst();
              lstOpcode.removeFirst();
              QString arguments;
              for (QStringList::iterator i = lstOpcode.begin(); i != lstOpcode.end(); ++i) {

                  arguments.append(*i);
              }
              arguments = arguments.remove("(");
              arguments = arguments.remove(")");
              QStringList arg_list = arguments.split(",");
              QVector<QString> args = arg_list.toVector();

              GDataDup* pdupData = new GDataDup(data_name, data_type, dup_value, args);
              psrcStr = new GSourceString(pdupData, nLineNum);
            }
            else if (strCodeLine.contains(single_data_regex)) {

                QString data_name = lstOpcode.at(0);
                QString data_type = lstOpcode.at(1);
                lstOpcode.removeFirst();
                lstOpcode.removeFirst();
                QString arguments;
                for (QStringList::iterator i = lstOpcode.begin(); i != lstOpcode.end(); ++i) {

                    arguments.append(*i);
                }
                QStringList arg_list = arguments.split(",");
                QVector<QString> args = arg_list.toVector();

                GData* psingleData = new GData(data_name, data_type, args);
                psrcStr = new GSourceString(psingleData, nLineNum);
            }
            else if(lstOpcode.count() == 3){
                //двухоперандные опкоды
                opcodeName = lstOpcode.at(0);
                oper1 = lstOpcode.at(1);
                oper1.truncate(oper1.count() - 1);
                oper2 = lstOpcode.at(2);

                if(opcodeName == "mov"){
                    GOpcodeMOV* popcodeMOV = new GOpcodeMOV(oper1, oper2);
                    psrcStr = new GSourceString(popcodeMOV, nLineNum);
                }
                else if(opcodeName == "adc"){
                    GOpcodeADC* popcodeADC = new GOpcodeADC(oper1, oper2);
                    psrcStr = new GSourceString(popcodeADC, nLineNum);
                }
                else if(opcodeName == "add"){
                    GOpcodeADD* popcodeADD = new GOpcodeADD(oper1, oper2);
                    psrcStr = new GSourceString(popcodeADD, nLineNum);
                }
                else if(opcodeName == "and"){
                    GOpcodeAND* popcodeAND = new GOpcodeAND(oper1, oper2);
                    psrcStr = new GSourceString(popcodeAND, nLineNum);
                }
                else if(opcodeName == "bt"){
                    GOpcodeBT* popcodeBT = new GOpcodeBT(oper1, oper2);
                    psrcStr = new GSourceString(popcodeBT, nLineNum);
                }
                else if(opcodeName == "btc"){
                    GOpcodeBTC* popcodeBTC = new GOpcodeBTC(oper1, oper2);
                    psrcStr = new GSourceString(popcodeBTC, nLineNum);
                }
                else if(opcodeName == "btr"){
                    GOpcodeBTR* popcodeBTR = new GOpcodeBTR(oper1, oper2);
                    psrcStr = new GSourceString(popcodeBTR, nLineNum);
                }
                else if(opcodeName == "bts"){
                    GOpcodeBTS* popcodeBTS = new GOpcodeBTS(oper1, oper2);
                    psrcStr = new GSourceString(popcodeBTS, nLineNum);
                }
                else if(opcodeName == "cmp"){
                    GOpcodeCMP* popcodeCMP = new GOpcodeCMP(oper1, oper2);
                    psrcStr = new GSourceString(popcodeCMP, nLineNum);
                }
                else if(opcodeName == "in"){
                    GOpcodeIN* popcodeIN = new GOpcodeIN(oper1, oper2);
                    psrcStr = new GSourceString(popcodeIN, nLineNum);
                }
                else if(opcodeName == "lds"){
                    GOpcodeLDS* popcodeLDS = new GOpcodeLDS(oper1, oper2);
                    psrcStr = new GSourceString(popcodeLDS, nLineNum);
                }
                else if(opcodeName == "lea"){
                    GOpcodeLEA* popcodeLEA = new GOpcodeLEA(oper1, oper2);
                    psrcStr = new GSourceString(popcodeLEA, nLineNum);
                }
                else if(opcodeName == "les"){
                    GOpcodeLES* popcodeLES = new GOpcodeLES(oper1, oper2);
                    psrcStr = new GSourceString(popcodeLES, nLineNum);
                }
                else if(opcodeName == "or"){
                    GOpcodeOR* popcodeOR = new GOpcodeOR(oper1, oper2);
                    psrcStr = new GSourceString(popcodeOR, nLineNum);
                }
                else if(opcodeName == "out"){
                    GOpcodeOUT* popcodeOUT = new GOpcodeOUT(oper1, oper2);
                    psrcStr = new GSourceString(popcodeOUT, nLineNum);
                }
                else if(opcodeName == "rcl"){
                    GOpcodeRCL* popcodeRCL = new GOpcodeRCL(oper1, oper2);
                    psrcStr = new GSourceString(popcodeRCL, nLineNum);
                }
                else if(opcodeName == "rcr"){
                    GOpcodeRCR* popcodeRCR = new GOpcodeRCR(oper1, oper2);
                    psrcStr = new GSourceString(popcodeRCR, nLineNum);
                }
                else if(opcodeName == "rol"){
                    GOpcodeROL* popcodeROL = new GOpcodeROL(oper1, oper2);
                    psrcStr = new GSourceString(popcodeROL, nLineNum);
                }
                else if(opcodeName == "ror"){
                    GOpcodeROR* popcodeROR = new GOpcodeROR(oper1, oper2);
                    psrcStr = new GSourceString(popcodeROR, nLineNum);
                }
                else if(opcodeName == "sal"){
                    GOpcodeSAL* popcodeSAL = new GOpcodeSAL(oper1, oper2);
                    psrcStr = new GSourceString(popcodeSAL, nLineNum);
                }
                else if(opcodeName == "sar"){
                    GOpcodeSAR* popcodeSAR = new GOpcodeSAR(oper1, oper2);
                    psrcStr = new GSourceString(popcodeSAR, nLineNum);
                }
                else if(opcodeName == "sbb"){
                    GOpcodeSBB* popcodeSBB = new GOpcodeSBB(oper1, oper2);
                    psrcStr = new GSourceString(popcodeSBB, nLineNum);
                }
                else if(opcodeName == "shl"){
                    GOpcodeSHL* popcodeSHL = new GOpcodeSHL(oper1, oper2);
                    psrcStr = new GSourceString(popcodeSHL, nLineNum);
                }
                else if(opcodeName == "shr"){
                    GOpcodeSHR* popcodeSHR = new GOpcodeSHR(oper1, oper2);
                    psrcStr = new GSourceString(popcodeSHR, nLineNum);
                }
                else if(opcodeName == "sub"){
                    GOpcodeSUB* popcodeSUB = new GOpcodeSUB(oper1, oper2);
                    psrcStr = new GSourceString(popcodeSUB, nLineNum);
                }
                else if(opcodeName == "test"){
                    GOpcodeTEST* popcodeTEST = new GOpcodeTEST(oper1, oper2);
                    psrcStr = new GSourceString(popcodeTEST, nLineNum);
                }
                else if(opcodeName == "xchg"){
                    GOpcodeXCHG* popcodeXCHG = new GOpcodeXCHG(oper1, oper2);
                    psrcStr = new GSourceString(popcodeXCHG, nLineNum);
                }
                else if(opcodeName == "xor"){
                    GOpcodeXOR* popcodeXOR = new GOpcodeXOR(oper1, oper2);
                    psrcStr = new GSourceString(popcodeXOR, nLineNum);
                }
                else{
                    QMessageBox::information(this, "OptAsm v1.0", "Двухоперандная команда не распознана");
                }
            }
            else if(lstOpcode.count() == 2){
                //однооперандные опкоды
                opcodeName = lstOpcode.at(0);
                oper1 = lstOpcode.at(1);

                if(opcodeName == "call"){
                    GOpcodeCALL* popcodeCALL = new GOpcodeCALL(oper1);
                    psrcStr = new GSourceString(popcodeCALL, nLineNum);
                }
                else if(opcodeName == "dec"){
                    GOpcodeDEC* popcodeDEC = new GOpcodeDEC(oper1);
                    psrcStr = new GSourceString(popcodeDEC, nLineNum);
                }
                else if(opcodeName == "div"){
                    GOpcodeDIV* popcodeDIV = new GOpcodeDIV(oper1);
                    psrcStr = new GSourceString(popcodeDIV, nLineNum);
                }
                else if(opcodeName == "idiv"){
                    GOpcodeIDIV* popcodeIDIV = new GOpcodeIDIV(oper1);
                    psrcStr = new GSourceString(popcodeIDIV, nLineNum);
                }
                else if(opcodeName == "imul"){
                    GOpcodeIMUL* popcodeIMUL = new GOpcodeIMUL(oper1);
                    psrcStr = new GSourceString(popcodeIMUL, nLineNum);
                }
                else if(opcodeName == "inc"){
                    GOpcodeINC* popcodeINC = new GOpcodeINC(oper1);
                    psrcStr = new GSourceString(popcodeINC, nLineNum);
                }
                else if(opcodeName == "int"){
                    GOpcodeINT* popcodeINT = new GOpcodeINT(oper1);
                    psrcStr = new GSourceString(popcodeINT, nLineNum);
                }
                else if(opcodeName == "ja"){
                    GOpcodeJA* popcodeJA = new GOpcodeJA(oper1);
                    psrcStr = new GSourceString(popcodeJA, nLineNum);
                }
                else if(opcodeName == "jae"){
                    GOpcodeJAE* popcodeJAE = new GOpcodeJAE(oper1);
                    psrcStr = new GSourceString(popcodeJAE, nLineNum);
                }
                else if(opcodeName == "jb"){
                    GOpcodeJB* popcodeJB = new GOpcodeJB(oper1);
                    psrcStr = new GSourceString(popcodeJB, nLineNum);
                }
                else if(opcodeName == "jbe"){
                    GOpcodeJBE* popcodeJBE = new GOpcodeJBE(oper1);
                    psrcStr = new GSourceString(popcodeJBE, nLineNum);
                }
                else if(opcodeName == "jc"){
                    GOpcodeJC* popcodeJC = new GOpcodeJC(oper1);
                    psrcStr = new GSourceString(popcodeJC, nLineNum);
                }
                else if(opcodeName == "jcxz"){
                    GOpcodeJCXZ* popcodeJCXZ = new GOpcodeJCXZ(oper1);
                    psrcStr = new GSourceString(popcodeJCXZ, nLineNum);
                }
                else if(opcodeName == "je"){
                    GOpcodeJE* popcodeJE = new GOpcodeJE(oper1);
                    psrcStr = new GSourceString(popcodeJE, nLineNum);
                }
                else if(opcodeName == "jg"){
                    GOpcodeJG* popcodeJG = new GOpcodeJG(oper1);
                    psrcStr = new GSourceString(popcodeJG, nLineNum);
                }
                else if(opcodeName == "jge"){
                    GOpcodeJGE* popcodeJGE = new GOpcodeJGE(oper1);
                    psrcStr = new GSourceString(popcodeJGE, nLineNum);
                }
                else if(opcodeName == "jl"){
                    GOpcodeJL* popcodeJL = new GOpcodeJL(oper1);
                    psrcStr = new GSourceString(popcodeJL, nLineNum);
                }
                else if(opcodeName == "jle"){
                    GOpcodeJLE* popcodeJLE = new GOpcodeJLE(oper1);
                    psrcStr = new GSourceString(popcodeJLE, nLineNum);
                }
                else if(opcodeName == "jmp"){
                    GOpcodeJMP* popcodeJMP = new GOpcodeJMP(oper1);
                    psrcStr = new GSourceString(popcodeJMP, nLineNum);
                }
                else if(opcodeName == "jna"){
                    GOpcodeJNA* popcodeJNA = new GOpcodeJNA(oper1);
                    psrcStr = new GSourceString(popcodeJNA, nLineNum);
                }
                else if(opcodeName == "jnae"){
                    GOpcodeJNAE* popcodeJNAE = new GOpcodeJNAE(oper1);
                    psrcStr = new GSourceString(popcodeJNAE, nLineNum);
                }
                else if(opcodeName == "jnb"){
                    GOpcodeJNB* popcodeJNB = new GOpcodeJNB(oper1);
                    psrcStr = new GSourceString(popcodeJNB, nLineNum);
                }
                else if(opcodeName == "jnbe"){
                    GOpcodeJNBE* popcodeJNBE = new GOpcodeJNBE(oper1);
                    psrcStr = new GSourceString(popcodeJNBE, nLineNum);
                }
                else if(opcodeName == "jnc"){
                    GOpcodeJNC* popcodeJNC = new GOpcodeJNC(oper1);
                    psrcStr = new GSourceString(popcodeJNC, nLineNum);
                }
                else if(opcodeName == "jne"){
                    GOpcodeJNE* popcodeJNE = new GOpcodeJNE(oper1);
                    psrcStr = new GSourceString(popcodeJNE, nLineNum);
                }
                else if(opcodeName == "jng"){
                    GOpcodeJNG* popcodeJNG = new GOpcodeJNG(oper1);
                    psrcStr = new GSourceString(popcodeJNG, nLineNum);
                }
                else if(opcodeName == "jnge"){
                    GOpcodeJNGE* popcodeJNGE = new GOpcodeJNGE(oper1);
                    psrcStr = new GSourceString(popcodeJNGE, nLineNum);
                }
                else if(opcodeName == "jnl"){
                    GOpcodeJNL* popcodeJNL = new GOpcodeJNL(oper1);
                    psrcStr = new GSourceString(popcodeJNL, nLineNum);
                }
                else if(opcodeName == "jnle"){
                    GOpcodeJNLE* popcodeJNLE = new GOpcodeJNLE(oper1);
                    psrcStr = new GSourceString(popcodeJNLE, nLineNum);
                }
                else if(opcodeName == "jno"){
                    GOpcodeJNO* popcodeJNO = new GOpcodeJNO(oper1);
                    psrcStr = new GSourceString(popcodeJNO, nLineNum);
                }
                else if(opcodeName == "jnp"){
                    GOpcodeJNP* popcodeJNP = new GOpcodeJNP(oper1);
                    psrcStr = new GSourceString(popcodeJNP, nLineNum);
                }
                else if(opcodeName == "jns"){
                    GOpcodeJNS* popcodeJNS = new GOpcodeJNS(oper1);
                    psrcStr = new GSourceString(popcodeJNS, nLineNum);
                }
                else if(opcodeName == "jnz"){
                    GOpcodeJNZ* popcodeJNZ = new GOpcodeJNZ(oper1);
                    psrcStr = new GSourceString(popcodeJNZ, nLineNum);
                }
                else if(opcodeName == "jo"){
                    GOpcodeJO* popcodeJO = new GOpcodeJO(oper1);
                    psrcStr = new GSourceString(popcodeJO, nLineNum);
                }
                else if(opcodeName == "jp"){
                    GOpcodeJP* popcodeJP = new GOpcodeJP(oper1);
                    psrcStr = new GSourceString(popcodeJP, nLineNum);
                }
                else if(opcodeName == "jpe"){
                    GOpcodeJPE* popcodeJPE = new GOpcodeJPE(oper1);
                    psrcStr = new GSourceString(popcodeJPE, nLineNum);
                }
                else if(opcodeName == "jpo"){
                    GOpcodeJPO* popcodeJPO = new GOpcodeJPO(oper1);
                    psrcStr = new GSourceString(popcodeJPO, nLineNum);
                }
                else if(opcodeName == "js"){
                    GOpcodeJS* popcodeJS = new GOpcodeJS(oper1);
                    psrcStr = new GSourceString(popcodeJS, nLineNum);
                }
                else if(opcodeName == "jz"){
                    GOpcodeJZ* popcodeJZ = new GOpcodeJZ(oper1);
                    psrcStr = new GSourceString(popcodeJZ, nLineNum);
                }
                else if(opcodeName == "loop"){
                    GOpcodeLOOP* popcodeLOOP = new GOpcodeLOOP(oper1);
                    psrcStr = new GSourceString(popcodeLOOP, nLineNum);
                }
                else if(opcodeName == "loope"){
                    GOpcodeLOOPE* popcodeLOOPE = new GOpcodeLOOPE(oper1);
                    psrcStr = new GSourceString(popcodeLOOPE, nLineNum);
                }
                else if(opcodeName == "loopne"){
                    GOpcodeLOOPNE* popcodeLOOPNE = new GOpcodeLOOPNE(oper1);
                    psrcStr = new GSourceString(popcodeLOOPNE, nLineNum);
                }
                else if(opcodeName == "loopnz"){
                    GOpcodeLOOPNZ* popcodeLOOPNZ = new GOpcodeLOOPNZ(oper1);
                    psrcStr = new GSourceString(popcodeLOOPNZ, nLineNum);
                }
                else if(opcodeName == "loopz"){
                    GOpcodeLOOPZ* popcodeLOOPZ = new GOpcodeLOOPZ(oper1);
                    psrcStr = new GSourceString(popcodeLOOPZ, nLineNum);
                }
                else if(opcodeName == "mul"){
                    GOpcodeMUL* popcodeMUL = new GOpcodeMUL(oper1);
                    psrcStr = new GSourceString(popcodeMUL, nLineNum);
                }
                else if(opcodeName == "neg"){
                    GOpcodeNEG* popcodeNEG = new GOpcodeNEG(oper1);
                    psrcStr = new GSourceString(popcodeNEG, nLineNum);
                }
                else if(opcodeName == "not"){
                    GOpcodeNOT* popcodeNOT = new GOpcodeNOT(oper1);
                    psrcStr = new GSourceString(popcodeNOT, nLineNum);
                }
                else if(opcodeName == "pop"){
                    GOpcodePOP* popcodePOP = new GOpcodePOP(oper1);
                    psrcStr = new GSourceString(popcodePOP, nLineNum);
                }
                else if(opcodeName == "push"){
                    GOpcodePUSH* popcodePUSH = new GOpcodePUSH(oper1);
                    psrcStr = new GSourceString(popcodePUSH, nLineNum);
                }
                else if(opcodeName == "ret"){
                    GOpcodeRET* popcodeRET = new GOpcodeRET(oper1);
                    psrcStr = new GSourceString(popcodeRET, nLineNum);
                }
                else{
                    QMessageBox::information(this, "OptAsm v1.0", "Однооперандная команда не распознана");
                }
            }
            else if(lstOpcode.count() == 1){
                // опкоды без операндов
                opcodeName = lstOpcode.at(0);
                if(opcodeName == "aaa"){
                    GOpcodeAAA* popcodeAAA = new GOpcodeAAA();
                    psrcStr = new GSourceString(popcodeAAA, nLineNum);
                }
                else if(opcodeName == "aad"){
                    GOpcodeAAD* popcodeAAD = new GOpcodeAAD();
                    psrcStr = new GSourceString(popcodeAAD, nLineNum);
                }
                else if(opcodeName == "aam"){
                    GOpcodeAAM* popcodeAAM = new GOpcodeAAM();
                    psrcStr = new GSourceString(popcodeAAM, nLineNum);
                }
                else if(opcodeName == "aas"){
                    GOpcodeAAS* popcodeAAS = new GOpcodeAAS();
                    psrcStr = new GSourceString(popcodeAAS, nLineNum);
                }
                else if(opcodeName == "cbw"){
                    GOpcodeCBW* popcodeCBW = new GOpcodeCBW();
                    psrcStr = new GSourceString(popcodeCBW, nLineNum);
                }
                else if(opcodeName == "clc"){
                    GOpcodeCLC* popcodeCLC = new GOpcodeCLC();
                    psrcStr = new GSourceString(popcodeCLC, nLineNum);
                }
                else if(opcodeName == "cld"){
                    GOpcodeCLD* popcodeCLD = new GOpcodeCLD();
                    psrcStr = new GSourceString(popcodeCLD, nLineNum);
                }
                else if(opcodeName == "cli"){
                    GOpcodeCLI* popcodeCLI = new GOpcodeCLI();
                    psrcStr = new GSourceString(popcodeCLI, nLineNum);
                }
                else if(opcodeName == "cmc"){
                    GOpcodeCMC* popcodeCMC = new GOpcodeCMC();
                    psrcStr = new GSourceString(popcodeCMC, nLineNum);
                }
                else if(opcodeName == "cwd"){
                    GOpcodeCWD* popcodeCWD = new GOpcodeCWD();
                    psrcStr = new GSourceString(popcodeCWD, nLineNum);
                }
                else if(opcodeName == "daa"){
                    GOpcodeDAA* popcodeDAA = new GOpcodeDAA();
                    psrcStr = new GSourceString(popcodeDAA, nLineNum);
                }
                else if(opcodeName == "das"){
                    GOpcodeDAS* popcodeDAS = new GOpcodeDAS();
                    psrcStr = new GSourceString(popcodeDAS, nLineNum);
                }
                else if(opcodeName == "esc"){
                    GOpcodeESC* popcodeESC = new GOpcodeESC();
                    psrcStr = new GSourceString(popcodeESC, nLineNum);
                }
                else if(opcodeName == "hlt"){
                    GOpcodeHLT* popcodeHLT = new GOpcodeHLT();
                    psrcStr = new GSourceString(popcodeHLT, nLineNum);
                }
                else if(opcodeName == "into"){
                    GOpcodeINTO* popcodeINTO = new GOpcodeINTO();
                    psrcStr = new GSourceString(popcodeINTO, nLineNum);
                }
                else if(opcodeName == "lahf"){
                    GOpcodeLAHF* popcodeLAHF = new GOpcodeLAHF();
                    psrcStr = new GSourceString(popcodeLAHF, nLineNum);
                }
                else if(opcodeName == "lock"){
                    GOpcodeLOCK* popcodeLOCK = new GOpcodeLOCK();
                    psrcStr = new GSourceString(popcodeLOCK, nLineNum);
                }
                else if(opcodeName == "nop"){
                    GOpcodeNOP* popcodeNOP = new GOpcodeNOP();
                    psrcStr = new GSourceString(popcodeNOP, nLineNum);
                }
                else if(opcodeName == "popf"){
                    GOpcodePOPF* popcodePOPF = new GOpcodePOPF();
                    psrcStr = new GSourceString(popcodePOPF, nLineNum);
                }
                else if(opcodeName == "pushf"){
                    GOpcodePUSHF* popcodePUSHF = new GOpcodePUSHF();
                    psrcStr = new GSourceString(popcodePUSHF, nLineNum);
                }
                else if(opcodeName == "sahf"){
                    GOpcodeSAHF* popcodeSAHF = new GOpcodeSAHF();
                    psrcStr = new GSourceString(popcodeSAHF, nLineNum);
                }
                else if(opcodeName == "stc"){
                    GOpcodeSTC* popcodeSTC = new GOpcodeSTC();
                    psrcStr = new GSourceString(popcodeSTC, nLineNum);
                }
                else if(opcodeName == "std"){
                    GOpcodeSTD* popcodeSTD = new GOpcodeSTD();
                    psrcStr = new GSourceString(popcodeSTD, nLineNum);
                }
                else if(opcodeName == "sti"){
                    GOpcodeSTI* popcodeSTI = new GOpcodeSTI();
                    psrcStr = new GSourceString(popcodeSTI, nLineNum);
                }
                else if(opcodeName == "wait"){
                    GOpcodeWAIT* popcodeWAIT = new GOpcodeWAIT();
                    psrcStr = new GSourceString(popcodeWAIT, nLineNum);
                }
                else if(opcodeName == "xlat"){
                    GOpcodeXLAT* popcodeXLAT = new GOpcodeXLAT();
                    psrcStr = new GSourceString(popcodeXLAT, nLineNum);
                }
                else{
                    QMessageBox::information(this, "OptAsm v1.0", "Безоперандная команда не распознана");
                }

            }
            else {
                QMessageBox::information(this, "OptAsm v1.0", "Инструкция не распознана");
            }
            //qDebug() << strCodeLine;
            m_ptheCode->addString(psrcStr);

        } //while(!in.atEnd())
        if(in.status() != QTextStream::Ok){
            QMessageBox::warning(this, "OptAsm v1.0", "Ошибка открытия");
        }
        file.close();
    }//if(file.open(QIODevice::ReadWrite))
}

void MainWindow::exitApp(void){
    //test1
//    QMessageBox::information(this, "getTicksBetweenLines", QString::number(this->m_ptheCode->getTicksBetweenLines(1, 3)));
//    QMessageBox::information(this, "GetCommonTicks", QString::number(this->m_ptheCode->getCommonTicks()));

    //test2
//    QMessageBox::information(this, "getBytesBetweenLines", QString::number(m_ptheCode->getBytesBetweenLines(1, 3)));
//    QMessageBox::information(this, "getCommonBytes", QString::number(m_ptheCode->getCommonBytes()));

    //test3
//    QVector<QPair<int, int>* >* vec = m_ptheCode->getAllCycles();
//    QVector<QPair<int, int>* >::iterator it;
//    QString mes;
//    for (it = vec->begin(); it != vec->end(); ++it) {

//        mes.append("\nbegin: ");
//        mes.append(QString::number((*it)->first));
//        mes.append("\nend: ");
//        mes.append(QString::number((*it)->second));
//    }
//    QMessageBox::information(this, "cycle", mes);

    //test4
    insertNOPs(2, 2);

    //предложить сохранить данные!
    QMessageBox* pmbx = new QMessageBox(QMessageBox::Question,
                                        "Выход из приложения",
                                        "Вы действительно хотите завершить работу с OptAsm?",
                                        QMessageBox::Yes | QMessageBox::Cancel);
    int n = pmbx->exec();
    delete pmbx;

    if(n == QMessageBox::Yes){
        //отобразить окно с благодарностью за использование optAsm на 2 секунды!
        qApp->quit();
    }
}

void MainWindow::insertNOP(int line){

    insertNOPs(line, 1);
}

void MainWindow::insertNOPs(int line, int count){

    //to string
    QString strCode = m_pteSource->toPlainText();
    QStringList str_lst = strCode.split("\n");
    QString strComplete;

    m_pteSource->clear();

    //TODO: inserting NOPs
    QStringList::iterator sit;
    int index = 0;
    for (sit = str_lst.begin(); sit != str_lst.end(); ++sit) {

        if (++index == line) {

            for (int  i_tmp = 0; i_tmp < count; ++i_tmp) {

                str_lst.insert(sit, QString("\tnop"));
            }

        }
    }


    //building the full text of program
    foreach(QString str, str_lst){
        strComplete.append(str);
        strComplete.append("\n");
    }


    //to GSourceString
    QTextStream in(&strComplete);
    QString strCodeLine;
    QStringList lstOpcode;
    QString opcodeName;
    QString oper1;
    QString oper2;

    QRegExp global_label_regex = QRegExp("^\\w+:$");
    QRegExp local_label_regex = QRegExp("^\\.\\w+:$");
    QRegExp unnamed_label_regex = QRegExp("^@@:$");
    QRegExp comment_regex = QRegExp("^;.+$");
    QRegExp single_data_regex = QRegExp("^\\w+\\s+(db|dw|du|dd|df|dp|dq|dt)\\s+.+$");
    QRegExp dup_data_regex = QRegExp("^\\w+\\s+(db|dw|du|dd|df|dp|dq|dt)\\s+\\d+\\s+dup\\s+\\(.+\\)$");

    int nLineNum(0);
    while(!in.atEnd()){
        ++nLineNum;
        strCodeLine = in.readLine();
        m_pteSource->append(strCodeLine);
        strCodeLine = strCodeLine.trimmed();
        lstOpcode = strCodeLine.split(" ");
        GSourceString* psrcStr;


        if (strCodeLine.contains(global_label_regex)) {

            //поиск глобальных меток
            strCodeLine = strCodeLine.remove(strCodeLine.length()-1, 1);
            GLabelGlobal* plabelGlobal = new GLabelGlobal(strCodeLine);
            psrcStr = new GSourceString(plabelGlobal, nLineNum);
        }
        else if (strCodeLine.contains(local_label_regex)) {

            //поиск локальных меток
            strCodeLine = strCodeLine.remove(strCodeLine.length()-1, 1);
            strCodeLine = strCodeLine.remove(0, 1);
            GLabelLocal* plabelLocal = new GLabelLocal(strCodeLine);
            psrcStr = new GSourceString(plabelLocal, nLineNum);
        }
        else if (strCodeLine.contains(unnamed_label_regex)) {

            //поиск безымянных меток
            GLabelUnnamed* plabelUnnamed = new GLabelUnnamed();
            psrcStr = new GSourceString(plabelUnnamed, nLineNum);
        }
        else if (strCodeLine.contains(comment_regex)) {

            //поиск комментария
            strCodeLine = strCodeLine.remove(0, 1);
            GComment* pcomment = new GComment(strCodeLine);
            psrcStr = new GSourceString(pcomment, nLineNum);
        }
        else if (strCodeLine.contains(dup_data_regex)) {

          QString data_name = lstOpcode.at(0);
          QString data_type = lstOpcode.at(1);
          QString dup_value = lstOpcode.at(2);
          lstOpcode.removeFirst();
          lstOpcode.removeFirst();
          lstOpcode.removeFirst();
          lstOpcode.removeFirst();
          QString arguments;
          for (QStringList::iterator i = lstOpcode.begin(); i != lstOpcode.end(); ++i) {

              arguments.append(*i);
          }
          arguments = arguments.remove("(");
          arguments = arguments.remove(")");
          QStringList arg_list = arguments.split(",");
          QVector<QString> args = arg_list.toVector();

          GDataDup* pdupData = new GDataDup(data_name, data_type, dup_value, args);
          psrcStr = new GSourceString(pdupData, nLineNum);
        }
        else if (strCodeLine.contains(single_data_regex)) {

            QString data_name = lstOpcode.at(0);
            QString data_type = lstOpcode.at(1);
            lstOpcode.removeFirst();
            lstOpcode.removeFirst();
            QString arguments;
            for (QStringList::iterator i = lstOpcode.begin(); i != lstOpcode.end(); ++i) {

                arguments.append(*i);
            }
            QStringList arg_list = arguments.split(",");
            QVector<QString> args = arg_list.toVector();

            GData* psingleData = new GData(data_name, data_type, args);
            psrcStr = new GSourceString(psingleData, nLineNum);
        }
        else if(lstOpcode.count() == 3){
            //двухоперандные опкоды
            opcodeName = lstOpcode.at(0);
            oper1 = lstOpcode.at(1);
            oper1.truncate(oper1.count() - 1);
            oper2 = lstOpcode.at(2);

            if(opcodeName == "mov"){
                GOpcodeMOV* popcodeMOV = new GOpcodeMOV(oper1, oper2);
                psrcStr = new GSourceString(popcodeMOV, nLineNum);
            }
            else if(opcodeName == "adc"){
                GOpcodeADC* popcodeADC = new GOpcodeADC(oper1, oper2);
                psrcStr = new GSourceString(popcodeADC, nLineNum);
            }
            else if(opcodeName == "add"){
                GOpcodeADD* popcodeADD = new GOpcodeADD(oper1, oper2);
                psrcStr = new GSourceString(popcodeADD, nLineNum);
            }
            else if(opcodeName == "and"){
                GOpcodeAND* popcodeAND = new GOpcodeAND(oper1, oper2);
                psrcStr = new GSourceString(popcodeAND, nLineNum);
            }
            else if(opcodeName == "bt"){
                GOpcodeBT* popcodeBT = new GOpcodeBT(oper1, oper2);
                psrcStr = new GSourceString(popcodeBT, nLineNum);
            }
            else if(opcodeName == "btc"){
                GOpcodeBTC* popcodeBTC = new GOpcodeBTC(oper1, oper2);
                psrcStr = new GSourceString(popcodeBTC, nLineNum);
            }
            else if(opcodeName == "btr"){
                GOpcodeBTR* popcodeBTR = new GOpcodeBTR(oper1, oper2);
                psrcStr = new GSourceString(popcodeBTR, nLineNum);
            }
            else if(opcodeName == "bts"){
                GOpcodeBTS* popcodeBTS = new GOpcodeBTS(oper1, oper2);
                psrcStr = new GSourceString(popcodeBTS, nLineNum);
            }
            else if(opcodeName == "cmp"){
                GOpcodeCMP* popcodeCMP = new GOpcodeCMP(oper1, oper2);
                psrcStr = new GSourceString(popcodeCMP, nLineNum);
            }
            else if(opcodeName == "in"){
                GOpcodeIN* popcodeIN = new GOpcodeIN(oper1, oper2);
                psrcStr = new GSourceString(popcodeIN, nLineNum);
            }
            else if(opcodeName == "lds"){
                GOpcodeLDS* popcodeLDS = new GOpcodeLDS(oper1, oper2);
                psrcStr = new GSourceString(popcodeLDS, nLineNum);
            }
            else if(opcodeName == "lea"){
                GOpcodeLEA* popcodeLEA = new GOpcodeLEA(oper1, oper2);
                psrcStr = new GSourceString(popcodeLEA, nLineNum);
            }
            else if(opcodeName == "les"){
                GOpcodeLES* popcodeLES = new GOpcodeLES(oper1, oper2);
                psrcStr = new GSourceString(popcodeLES, nLineNum);
            }
            else if(opcodeName == "or"){
                GOpcodeOR* popcodeOR = new GOpcodeOR(oper1, oper2);
                psrcStr = new GSourceString(popcodeOR, nLineNum);
            }
            else if(opcodeName == "out"){
                GOpcodeOUT* popcodeOUT = new GOpcodeOUT(oper1, oper2);
                psrcStr = new GSourceString(popcodeOUT, nLineNum);
            }
            else if(opcodeName == "rcl"){
                GOpcodeRCL* popcodeRCL = new GOpcodeRCL(oper1, oper2);
                psrcStr = new GSourceString(popcodeRCL, nLineNum);
            }
            else if(opcodeName == "rcr"){
                GOpcodeRCR* popcodeRCR = new GOpcodeRCR(oper1, oper2);
                psrcStr = new GSourceString(popcodeRCR, nLineNum);
            }
            else if(opcodeName == "rol"){
                GOpcodeROL* popcodeROL = new GOpcodeROL(oper1, oper2);
                psrcStr = new GSourceString(popcodeROL, nLineNum);
            }
            else if(opcodeName == "ror"){
                GOpcodeROR* popcodeROR = new GOpcodeROR(oper1, oper2);
                psrcStr = new GSourceString(popcodeROR, nLineNum);
            }
            else if(opcodeName == "sal"){
                GOpcodeSAL* popcodeSAL = new GOpcodeSAL(oper1, oper2);
                psrcStr = new GSourceString(popcodeSAL, nLineNum);
            }
            else if(opcodeName == "sar"){
                GOpcodeSAR* popcodeSAR = new GOpcodeSAR(oper1, oper2);
                psrcStr = new GSourceString(popcodeSAR, nLineNum);
            }
            else if(opcodeName == "sbb"){
                GOpcodeSBB* popcodeSBB = new GOpcodeSBB(oper1, oper2);
                psrcStr = new GSourceString(popcodeSBB, nLineNum);
            }
            else if(opcodeName == "shl"){
                GOpcodeSHL* popcodeSHL = new GOpcodeSHL(oper1, oper2);
                psrcStr = new GSourceString(popcodeSHL, nLineNum);
            }
            else if(opcodeName == "shr"){
                GOpcodeSHR* popcodeSHR = new GOpcodeSHR(oper1, oper2);
                psrcStr = new GSourceString(popcodeSHR, nLineNum);
            }
            else if(opcodeName == "sub"){
                GOpcodeSUB* popcodeSUB = new GOpcodeSUB(oper1, oper2);
                psrcStr = new GSourceString(popcodeSUB, nLineNum);
            }
            else if(opcodeName == "test"){
                GOpcodeTEST* popcodeTEST = new GOpcodeTEST(oper1, oper2);
                psrcStr = new GSourceString(popcodeTEST, nLineNum);
            }
            else if(opcodeName == "xchg"){
                GOpcodeXCHG* popcodeXCHG = new GOpcodeXCHG(oper1, oper2);
                psrcStr = new GSourceString(popcodeXCHG, nLineNum);
            }
            else if(opcodeName == "xor"){
                GOpcodeXOR* popcodeXOR = new GOpcodeXOR(oper1, oper2);
                psrcStr = new GSourceString(popcodeXOR, nLineNum);
            }
            else{
                QMessageBox::information(this, "OptAsm v1.0", "Двухоперандная команда не распознана");
            }
        }
        else if(lstOpcode.count() == 2){
            //однооперандные опкоды
            opcodeName = lstOpcode.at(0);
            oper1 = lstOpcode.at(1);

            if(opcodeName == "call"){
                GOpcodeCALL* popcodeCALL = new GOpcodeCALL(oper1);
                psrcStr = new GSourceString(popcodeCALL, nLineNum);
            }
            else if(opcodeName == "dec"){
                GOpcodeDEC* popcodeDEC = new GOpcodeDEC(oper1);
                psrcStr = new GSourceString(popcodeDEC, nLineNum);
            }
            else if(opcodeName == "div"){
                GOpcodeDIV* popcodeDIV = new GOpcodeDIV(oper1);
                psrcStr = new GSourceString(popcodeDIV, nLineNum);
            }
            else if(opcodeName == "idiv"){
                GOpcodeIDIV* popcodeIDIV = new GOpcodeIDIV(oper1);
                psrcStr = new GSourceString(popcodeIDIV, nLineNum);
            }
            else if(opcodeName == "imul"){
                GOpcodeIMUL* popcodeIMUL = new GOpcodeIMUL(oper1);
                psrcStr = new GSourceString(popcodeIMUL, nLineNum);
            }
            else if(opcodeName == "inc"){
                GOpcodeINC* popcodeINC = new GOpcodeINC(oper1);
                psrcStr = new GSourceString(popcodeINC, nLineNum);
            }
            else if(opcodeName == "int"){
                GOpcodeINT* popcodeINT = new GOpcodeINT(oper1);
                psrcStr = new GSourceString(popcodeINT, nLineNum);
            }
            else if(opcodeName == "ja"){
                GOpcodeJA* popcodeJA = new GOpcodeJA(oper1);
                psrcStr = new GSourceString(popcodeJA, nLineNum);
            }
            else if(opcodeName == "jae"){
                GOpcodeJAE* popcodeJAE = new GOpcodeJAE(oper1);
                psrcStr = new GSourceString(popcodeJAE, nLineNum);
            }
            else if(opcodeName == "jb"){
                GOpcodeJB* popcodeJB = new GOpcodeJB(oper1);
                psrcStr = new GSourceString(popcodeJB, nLineNum);
            }
            else if(opcodeName == "jbe"){
                GOpcodeJBE* popcodeJBE = new GOpcodeJBE(oper1);
                psrcStr = new GSourceString(popcodeJBE, nLineNum);
            }
            else if(opcodeName == "jc"){
                GOpcodeJC* popcodeJC = new GOpcodeJC(oper1);
                psrcStr = new GSourceString(popcodeJC, nLineNum);
            }
            else if(opcodeName == "jcxz"){
                GOpcodeJCXZ* popcodeJCXZ = new GOpcodeJCXZ(oper1);
                psrcStr = new GSourceString(popcodeJCXZ, nLineNum);
            }
            else if(opcodeName == "je"){
                GOpcodeJE* popcodeJE = new GOpcodeJE(oper1);
                psrcStr = new GSourceString(popcodeJE, nLineNum);
            }
            else if(opcodeName == "jg"){
                GOpcodeJG* popcodeJG = new GOpcodeJG(oper1);
                psrcStr = new GSourceString(popcodeJG, nLineNum);
            }
            else if(opcodeName == "jge"){
                GOpcodeJGE* popcodeJGE = new GOpcodeJGE(oper1);
                psrcStr = new GSourceString(popcodeJGE, nLineNum);
            }
            else if(opcodeName == "jl"){
                GOpcodeJL* popcodeJL = new GOpcodeJL(oper1);
                psrcStr = new GSourceString(popcodeJL, nLineNum);
            }
            else if(opcodeName == "jle"){
                GOpcodeJLE* popcodeJLE = new GOpcodeJLE(oper1);
                psrcStr = new GSourceString(popcodeJLE, nLineNum);
            }
            else if(opcodeName == "jmp"){
                GOpcodeJMP* popcodeJMP = new GOpcodeJMP(oper1);
                psrcStr = new GSourceString(popcodeJMP, nLineNum);
            }
            else if(opcodeName == "jna"){
                GOpcodeJNA* popcodeJNA = new GOpcodeJNA(oper1);
                psrcStr = new GSourceString(popcodeJNA, nLineNum);
            }
            else if(opcodeName == "jnae"){
                GOpcodeJNAE* popcodeJNAE = new GOpcodeJNAE(oper1);
                psrcStr = new GSourceString(popcodeJNAE, nLineNum);
            }
            else if(opcodeName == "jnb"){
                GOpcodeJNB* popcodeJNB = new GOpcodeJNB(oper1);
                psrcStr = new GSourceString(popcodeJNB, nLineNum);
            }
            else if(opcodeName == "jnbe"){
                GOpcodeJNBE* popcodeJNBE = new GOpcodeJNBE(oper1);
                psrcStr = new GSourceString(popcodeJNBE, nLineNum);
            }
            else if(opcodeName == "jnc"){
                GOpcodeJNC* popcodeJNC = new GOpcodeJNC(oper1);
                psrcStr = new GSourceString(popcodeJNC, nLineNum);
            }
            else if(opcodeName == "jne"){
                GOpcodeJNE* popcodeJNE = new GOpcodeJNE(oper1);
                psrcStr = new GSourceString(popcodeJNE, nLineNum);
            }
            else if(opcodeName == "jng"){
                GOpcodeJNG* popcodeJNG = new GOpcodeJNG(oper1);
                psrcStr = new GSourceString(popcodeJNG, nLineNum);
            }
            else if(opcodeName == "jnge"){
                GOpcodeJNGE* popcodeJNGE = new GOpcodeJNGE(oper1);
                psrcStr = new GSourceString(popcodeJNGE, nLineNum);
            }
            else if(opcodeName == "jnl"){
                GOpcodeJNL* popcodeJNL = new GOpcodeJNL(oper1);
                psrcStr = new GSourceString(popcodeJNL, nLineNum);
            }
            else if(opcodeName == "jnle"){
                GOpcodeJNLE* popcodeJNLE = new GOpcodeJNLE(oper1);
                psrcStr = new GSourceString(popcodeJNLE, nLineNum);
            }
            else if(opcodeName == "jno"){
                GOpcodeJNO* popcodeJNO = new GOpcodeJNO(oper1);
                psrcStr = new GSourceString(popcodeJNO, nLineNum);
            }
            else if(opcodeName == "jnp"){
                GOpcodeJNP* popcodeJNP = new GOpcodeJNP(oper1);
                psrcStr = new GSourceString(popcodeJNP, nLineNum);
            }
            else if(opcodeName == "jns"){
                GOpcodeJNS* popcodeJNS = new GOpcodeJNS(oper1);
                psrcStr = new GSourceString(popcodeJNS, nLineNum);
            }
            else if(opcodeName == "jnz"){
                GOpcodeJNZ* popcodeJNZ = new GOpcodeJNZ(oper1);
                psrcStr = new GSourceString(popcodeJNZ, nLineNum);
            }
            else if(opcodeName == "jo"){
                GOpcodeJO* popcodeJO = new GOpcodeJO(oper1);
                psrcStr = new GSourceString(popcodeJO, nLineNum);
            }
            else if(opcodeName == "jp"){
                GOpcodeJP* popcodeJP = new GOpcodeJP(oper1);
                psrcStr = new GSourceString(popcodeJP, nLineNum);
            }
            else if(opcodeName == "jpe"){
                GOpcodeJPE* popcodeJPE = new GOpcodeJPE(oper1);
                psrcStr = new GSourceString(popcodeJPE, nLineNum);
            }
            else if(opcodeName == "jpo"){
                GOpcodeJPO* popcodeJPO = new GOpcodeJPO(oper1);
                psrcStr = new GSourceString(popcodeJPO, nLineNum);
            }
            else if(opcodeName == "js"){
                GOpcodeJS* popcodeJS = new GOpcodeJS(oper1);
                psrcStr = new GSourceString(popcodeJS, nLineNum);
            }
            else if(opcodeName == "jz"){
                GOpcodeJZ* popcodeJZ = new GOpcodeJZ(oper1);
                psrcStr = new GSourceString(popcodeJZ, nLineNum);
            }
            else if(opcodeName == "loop"){
                GOpcodeLOOP* popcodeLOOP = new GOpcodeLOOP(oper1);
                psrcStr = new GSourceString(popcodeLOOP, nLineNum);
            }
            else if(opcodeName == "loope"){
                GOpcodeLOOPE* popcodeLOOPE = new GOpcodeLOOPE(oper1);
                psrcStr = new GSourceString(popcodeLOOPE, nLineNum);
            }
            else if(opcodeName == "loopne"){
                GOpcodeLOOPNE* popcodeLOOPNE = new GOpcodeLOOPNE(oper1);
                psrcStr = new GSourceString(popcodeLOOPNE, nLineNum);
            }
            else if(opcodeName == "loopnz"){
                GOpcodeLOOPNZ* popcodeLOOPNZ = new GOpcodeLOOPNZ(oper1);
                psrcStr = new GSourceString(popcodeLOOPNZ, nLineNum);
            }
            else if(opcodeName == "loopz"){
                GOpcodeLOOPZ* popcodeLOOPZ = new GOpcodeLOOPZ(oper1);
                psrcStr = new GSourceString(popcodeLOOPZ, nLineNum);
            }
            else if(opcodeName == "mul"){
                GOpcodeMUL* popcodeMUL = new GOpcodeMUL(oper1);
                psrcStr = new GSourceString(popcodeMUL, nLineNum);
            }
            else if(opcodeName == "neg"){
                GOpcodeNEG* popcodeNEG = new GOpcodeNEG(oper1);
                psrcStr = new GSourceString(popcodeNEG, nLineNum);
            }
            else if(opcodeName == "not"){
                GOpcodeNOT* popcodeNOT = new GOpcodeNOT(oper1);
                psrcStr = new GSourceString(popcodeNOT, nLineNum);
            }
            else if(opcodeName == "pop"){
                GOpcodePOP* popcodePOP = new GOpcodePOP(oper1);
                psrcStr = new GSourceString(popcodePOP, nLineNum);
            }
            else if(opcodeName == "push"){
                GOpcodePUSH* popcodePUSH = new GOpcodePUSH(oper1);
                psrcStr = new GSourceString(popcodePUSH, nLineNum);
            }
            else if(opcodeName == "ret"){
                GOpcodeRET* popcodeRET = new GOpcodeRET(oper1);
                psrcStr = new GSourceString(popcodeRET, nLineNum);
            }
            else{
                QMessageBox::information(this, "OptAsm v1.0", "Однооперандная команда не распознана");
            }
        }
        else if(lstOpcode.count() == 1){
            // опкоды без операндов
            opcodeName = lstOpcode.at(0);
            if(opcodeName == "aaa"){
                GOpcodeAAA* popcodeAAA = new GOpcodeAAA();
                psrcStr = new GSourceString(popcodeAAA, nLineNum);
            }
            else if(opcodeName == "aad"){
                GOpcodeAAD* popcodeAAD = new GOpcodeAAD();
                psrcStr = new GSourceString(popcodeAAD, nLineNum);
            }
            else if(opcodeName == "aam"){
                GOpcodeAAM* popcodeAAM = new GOpcodeAAM();
                psrcStr = new GSourceString(popcodeAAM, nLineNum);
            }
            else if(opcodeName == "aas"){
                GOpcodeAAS* popcodeAAS = new GOpcodeAAS();
                psrcStr = new GSourceString(popcodeAAS, nLineNum);
            }
            else if(opcodeName == "cbw"){
                GOpcodeCBW* popcodeCBW = new GOpcodeCBW();
                psrcStr = new GSourceString(popcodeCBW, nLineNum);
            }
            else if(opcodeName == "clc"){
                GOpcodeCLC* popcodeCLC = new GOpcodeCLC();
                psrcStr = new GSourceString(popcodeCLC, nLineNum);
            }
            else if(opcodeName == "cld"){
                GOpcodeCLD* popcodeCLD = new GOpcodeCLD();
                psrcStr = new GSourceString(popcodeCLD, nLineNum);
            }
            else if(opcodeName == "cli"){
                GOpcodeCLI* popcodeCLI = new GOpcodeCLI();
                psrcStr = new GSourceString(popcodeCLI, nLineNum);
            }
            else if(opcodeName == "cmc"){
                GOpcodeCMC* popcodeCMC = new GOpcodeCMC();
                psrcStr = new GSourceString(popcodeCMC, nLineNum);
            }
            else if(opcodeName == "cwd"){
                GOpcodeCWD* popcodeCWD = new GOpcodeCWD();
                psrcStr = new GSourceString(popcodeCWD, nLineNum);
            }
            else if(opcodeName == "daa"){
                GOpcodeDAA* popcodeDAA = new GOpcodeDAA();
                psrcStr = new GSourceString(popcodeDAA, nLineNum);
            }
            else if(opcodeName == "das"){
                GOpcodeDAS* popcodeDAS = new GOpcodeDAS();
                psrcStr = new GSourceString(popcodeDAS, nLineNum);
            }
            else if(opcodeName == "esc"){
                GOpcodeESC* popcodeESC = new GOpcodeESC();
                psrcStr = new GSourceString(popcodeESC, nLineNum);
            }
            else if(opcodeName == "hlt"){
                GOpcodeHLT* popcodeHLT = new GOpcodeHLT();
                psrcStr = new GSourceString(popcodeHLT, nLineNum);
            }
            else if(opcodeName == "into"){
                GOpcodeINTO* popcodeINTO = new GOpcodeINTO();
                psrcStr = new GSourceString(popcodeINTO, nLineNum);
            }
            else if(opcodeName == "lahf"){
                GOpcodeLAHF* popcodeLAHF = new GOpcodeLAHF();
                psrcStr = new GSourceString(popcodeLAHF, nLineNum);
            }
            else if(opcodeName == "lock"){
                GOpcodeLOCK* popcodeLOCK = new GOpcodeLOCK();
                psrcStr = new GSourceString(popcodeLOCK, nLineNum);
            }
            else if(opcodeName == "nop"){
                GOpcodeNOP* popcodeNOP = new GOpcodeNOP();
                psrcStr = new GSourceString(popcodeNOP, nLineNum);
            }
            else if(opcodeName == "popf"){
                GOpcodePOPF* popcodePOPF = new GOpcodePOPF();
                psrcStr = new GSourceString(popcodePOPF, nLineNum);
            }
            else if(opcodeName == "pushf"){
                GOpcodePUSHF* popcodePUSHF = new GOpcodePUSHF();
                psrcStr = new GSourceString(popcodePUSHF, nLineNum);
            }
            else if(opcodeName == "sahf"){
                GOpcodeSAHF* popcodeSAHF = new GOpcodeSAHF();
                psrcStr = new GSourceString(popcodeSAHF, nLineNum);
            }
            else if(opcodeName == "stc"){
                GOpcodeSTC* popcodeSTC = new GOpcodeSTC();
                psrcStr = new GSourceString(popcodeSTC, nLineNum);
            }
            else if(opcodeName == "std"){
                GOpcodeSTD* popcodeSTD = new GOpcodeSTD();
                psrcStr = new GSourceString(popcodeSTD, nLineNum);
            }
            else if(opcodeName == "sti"){
                GOpcodeSTI* popcodeSTI = new GOpcodeSTI();
                psrcStr = new GSourceString(popcodeSTI, nLineNum);
            }
            else if(opcodeName == "wait"){
                GOpcodeWAIT* popcodeWAIT = new GOpcodeWAIT();
                psrcStr = new GSourceString(popcodeWAIT, nLineNum);
            }
            else if(opcodeName == "xlat"){
                GOpcodeXLAT* popcodeXLAT = new GOpcodeXLAT();
                psrcStr = new GSourceString(popcodeXLAT, nLineNum);
            }
            else{
                QMessageBox::information(this, "OptAsm v1.0", "Безоперандная команда не распознана");
            }

        }
        else {
            QMessageBox::information(this, "OptAsm v1.0", "Инструкция не распознана");
        }
        //qDebug() << strCodeLine;
        m_ptheCode->addString(psrcStr);

    } //while(!in.atEnd())
    if(in.status() != QTextStream::Ok){
        QMessageBox::warning(this, "OptAsm v1.0", "Ошибка обновления");
    }

    //update number of line
    m_nNumberOfLine = str_lst.count() + 1;
    m_plcdNumberOfLine->display(m_nNumberOfLine);
    if(m_nNumberOfLine != 1){
        m_pcmdLineDown->setEnabled(true);
    }
}

