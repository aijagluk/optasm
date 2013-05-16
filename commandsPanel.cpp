/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (aijagluk@gmail.com)          *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2012 *
**********************************************************************/

#include <QListWidget>
#include <QVBoxLayout>
#include "commandsPanel.h"

GCommandsPanel::GCommandsPanel(QWidget *parent) :
    QWidget(parent){

    this->m_ptoolCommandsPanel = new QToolBox();


    QListWidget* plistMoveDataCommands = new QListWidget();
    QListWidgetItem* plstItem_mov = new QListWidgetItem("mov", plistMoveDataCommands);
    QListWidgetItem* plstItem_xchg = new QListWidgetItem("xchg", plistMoveDataCommands);
    QListWidgetItem* plstItem_xlat = new QListWidgetItem("xlat", plistMoveDataCommands);
    QListWidgetItem* plstItem_lea = new QListWidgetItem("lea", plistMoveDataCommands);
    QListWidgetItem* plstItem_lds = new QListWidgetItem("lds", plistMoveDataCommands);
    QListWidgetItem* plstItem_les = new QListWidgetItem("les", plistMoveDataCommands);


    QListWidget* plistSendFlagsCommands = new QListWidget();
    QListWidgetItem* plstItem_lahf = new QListWidgetItem("lahf", plistSendFlagsCommands);
    QListWidgetItem* plstItem_sahf = new QListWidgetItem("sahf", plistSendFlagsCommands);


    QListWidget* plistStackCommands = new QListWidget();
    QListWidgetItem* plstItem_push = new QListWidgetItem("push", plistStackCommands);
    QListWidgetItem* plstItem_pop = new QListWidgetItem("pop", plistStackCommands);
    QListWidgetItem* plstItem_pushf = new QListWidgetItem("pushf", plistStackCommands);
    QListWidgetItem* plstItem_popf = new QListWidgetItem("popf", plistStackCommands);


    QListWidget* plistIOCommands = new QListWidget();
    QListWidgetItem* plstItem_in = new QListWidgetItem("in", plistIOCommands);
    QListWidgetItem* plstItem_out = new QListWidgetItem("out", plistIOCommands);


    QListWidget* plistAddingCommands = new QListWidget();
    QListWidgetItem* plstItem_add = new QListWidgetItem("add", plistAddingCommands);
    QListWidgetItem* plstItem_adc = new QListWidgetItem("adc", plistAddingCommands);


    QListWidget* plistSubtractCommands = new QListWidget();
    QListWidgetItem* plstItem_sub = new QListWidgetItem("sub", plistSubtractCommands);
    QListWidgetItem* plstItem_sbb = new QListWidgetItem("sbb", plistSubtractCommands);
    QListWidgetItem* plstItem_cmp = new QListWidgetItem("cmp", plistSubtractCommands);


    QListWidget* plistMulDivCommands = new QListWidget();
    QListWidgetItem* plstItem_mul = new QListWidgetItem("mul", plistMulDivCommands);
    QListWidgetItem* plstItem_imul = new QListWidgetItem("imul", plistMulDivCommands);
    QListWidgetItem* plstItem_div = new QListWidgetItem("div", plistMulDivCommands);
    QListWidgetItem* plstItem_idiv = new QListWidgetItem("idiv", plistMulDivCommands);


    QListWidget* plistArithmOneOpCommands = new QListWidget();
    QListWidgetItem* plstItem_inc = new QListWidgetItem("inc", plistArithmOneOpCommands);
    QListWidgetItem* plstItem_dec = new QListWidgetItem("dec", plistArithmOneOpCommands);
    QListWidgetItem* plstItem_neg = new QListWidgetItem("neg", plistArithmOneOpCommands);


    QListWidget* plistTransformCommands = new QListWidget();
    QListWidgetItem* plstItem_cbw = new QListWidgetItem("cbw", plistTransformCommands);
    QListWidgetItem* plstItem_cwd = new QListWidgetItem("cwd", plistTransformCommands);


    QListWidget* plistBinaryCorrectionCommands = new QListWidget();
    QListWidgetItem* plstItem_bcd = new QListWidgetItem("bcd", plistBinaryCorrectionCommands);
    QListWidgetItem* plstItem_daa = new QListWidgetItem("daa", plistBinaryCorrectionCommands);
    QListWidgetItem* plstItem_das = new QListWidgetItem("das", plistBinaryCorrectionCommands);


    QListWidget* plistSymbolCorrectionCommands = new QListWidget();
    QListWidgetItem* plstItem_aaa   = new QListWidgetItem("aaa", plistSymbolCorrectionCommands);
    QListWidgetItem* plstItem_aas = new QListWidgetItem("aas", plistSymbolCorrectionCommands);
    QListWidgetItem* plstItem_aam = new QListWidgetItem("aam", plistSymbolCorrectionCommands);
    QListWidgetItem* plstItem_aad = new QListWidgetItem("aad", plistSymbolCorrectionCommands);

    QListWidget* plistBitsManageCommands = new QListWidget();
    QListWidgetItem* plstItem_bt   = new QListWidgetItem("bt", plistBitsManageCommands);
    QListWidgetItem* plstItem_btc = new QListWidgetItem("btc", plistBitsManageCommands);
    QListWidgetItem* plstItem_btr = new QListWidgetItem("btr", plistBitsManageCommands);
    QListWidgetItem* plstItem_bts = new QListWidgetItem("bts", plistBitsManageCommands);


    QListWidget* plistLogicCommands = new QListWidget();
    QListWidgetItem* plstItem_and   = new QListWidgetItem("and", plistLogicCommands);
    QListWidgetItem* plstItem_or = new QListWidgetItem("or", plistLogicCommands);
    QListWidgetItem* plstItem_xor = new QListWidgetItem("xor", plistLogicCommands);
    QListWidgetItem* plstItem_test = new QListWidgetItem("test", plistLogicCommands);
    QListWidgetItem* plstItem_not = new QListWidgetItem("not", plistLogicCommands);



    QListWidget* plistShiftCommands = new QListWidget();
    QListWidgetItem* plstItem_rcl = new QListWidgetItem("rcl", plistShiftCommands);
    QListWidgetItem* plstItem_rcr = new QListWidgetItem("rcr", plistShiftCommands);
    QListWidgetItem* plstItem_rol = new QListWidgetItem("rol", plistShiftCommands);
    QListWidgetItem* plstItem_ror = new QListWidgetItem("ror", plistShiftCommands);
    QListWidgetItem* plstItem_sal = new QListWidgetItem("sal", plistShiftCommands);
    QListWidgetItem* plstItem_sar = new QListWidgetItem("sar", plistShiftCommands);
    QListWidgetItem* plstItem_shl = new QListWidgetItem("shl", plistShiftCommands);
    QListWidgetItem* plstItem_shr = new QListWidgetItem("shr", plistShiftCommands);


    QListWidget* plistStringCommands = new QListWidget();
    QListWidgetItem* plstItem_movs = new QListWidgetItem("movs", plistStringCommands);
    QListWidgetItem* plstItem_movsb = new QListWidgetItem("movsb", plistStringCommands);
    QListWidgetItem* plstItem_movsw = new QListWidgetItem("movsw", plistStringCommands);
    QListWidgetItem* plstItem_cmps = new QListWidgetItem("cmps", plistStringCommands);
    QListWidgetItem* plstItem_cmpsb = new QListWidgetItem("cmpsb", plistStringCommands);
    QListWidgetItem* plstItem_cmpsw = new QListWidgetItem("cmpsw", plistStringCommands);
    QListWidgetItem* plstItem_scas = new QListWidgetItem("scas", plistStringCommands);
    QListWidgetItem* plstItem_scasb = new QListWidgetItem("scasb", plistStringCommands);
    QListWidgetItem* plstItem_scasw = new QListWidgetItem("scasw", plistStringCommands);
    QListWidgetItem* plstItem_lods = new QListWidgetItem("lods", plistStringCommands);
    QListWidgetItem* plstItem_lodsb = new QListWidgetItem("lodsb", plistStringCommands);
    QListWidgetItem* plstItem_lodsw = new QListWidgetItem("lodsw", plistStringCommands);
    QListWidgetItem* plstItem_stos = new QListWidgetItem("stos", plistStringCommands);
    QListWidgetItem* plstItem_stosb = new QListWidgetItem("stosb", plistStringCommands);
    QListWidgetItem* plstItem_stosw = new QListWidgetItem("stosw", plistStringCommands);


    QListWidget* plistUncondJumpCommands = new QListWidget();
    QListWidgetItem* plstItem_jmp = new QListWidgetItem("jmp", plistUncondJumpCommands);
    QListWidgetItem* plstItem_call = new QListWidgetItem("call", plistUncondJumpCommands);
    QListWidgetItem* plstItem_ret = new QListWidgetItem("ret", plistUncondJumpCommands);


    QListWidget* plistCondJumpCommands = new QListWidget();
    QListWidgetItem* plstItem_jl = new QListWidgetItem("jl", plistCondJumpCommands);
    QListWidgetItem* plstItem_jnge = new QListWidgetItem("jnge", plistCondJumpCommands);
    QListWidgetItem* plstItem_jnl = new QListWidgetItem("jnl", plistCondJumpCommands);
    QListWidgetItem* plstItem_jge = new QListWidgetItem("jge", plistCondJumpCommands);
    QListWidgetItem* plstItem_jle = new QListWidgetItem("jle", plistCondJumpCommands);
    QListWidgetItem* plstItem_jng = new QListWidgetItem("jng", plistCondJumpCommands);
    QListWidgetItem* plstItem_jnle = new QListWidgetItem("jnle", plistCondJumpCommands);
    QListWidgetItem* plstItem_jg = new QListWidgetItem("jg", plistCondJumpCommands);
    QListWidgetItem* plstItem_jb = new QListWidgetItem("jb", plistCondJumpCommands);
    QListWidgetItem* plstItem_jnae = new QListWidgetItem("jnae", plistCondJumpCommands);
    QListWidgetItem* plstItem_jc = new QListWidgetItem("jc", plistCondJumpCommands);
    QListWidgetItem* plstItem_jbe = new QListWidgetItem("jbe", plistCondJumpCommands);
    QListWidgetItem* plstItem_jna = new QListWidgetItem("jna", plistCondJumpCommands);
    QListWidgetItem* plstItem_jnb = new QListWidgetItem("jnb", plistCondJumpCommands);
    QListWidgetItem* plstItem_jae = new QListWidgetItem("jae", plistCondJumpCommands);
    QListWidgetItem* plstItem_jnc = new QListWidgetItem("jnc", plistCondJumpCommands);
    QListWidgetItem* plstItem_jnbe = new QListWidgetItem("jnbe", plistCondJumpCommands);
    QListWidgetItem* plstItem_ja = new QListWidgetItem("ja", plistCondJumpCommands);
    QListWidgetItem* plstItem_je = new QListWidgetItem("je", plistCondJumpCommands);
    QListWidgetItem* plstItem_jz = new QListWidgetItem("jz", plistCondJumpCommands);
    QListWidgetItem* plstItem_jp = new QListWidgetItem("jp", plistCondJumpCommands);
    QListWidgetItem* plstItem_jpe = new QListWidgetItem("jpe", plistCondJumpCommands);
    QListWidgetItem* plstItem_jo = new QListWidgetItem("jo", plistCondJumpCommands);
    QListWidgetItem* plstItem_js = new QListWidgetItem("js", plistCondJumpCommands);
    QListWidgetItem* plstItem_jne = new QListWidgetItem("jne", plistCondJumpCommands);
    QListWidgetItem* plstItem_jnz = new QListWidgetItem("jnz", plistCondJumpCommands);
    QListWidgetItem* plstItem_jnp = new QListWidgetItem("jnp", plistCondJumpCommands);
    QListWidgetItem* plstItem_jpo = new QListWidgetItem("jpo", plistCondJumpCommands);
    QListWidgetItem* plstItem_jno = new QListWidgetItem("jno", plistCondJumpCommands);
    QListWidgetItem* plstItem_jns = new QListWidgetItem("jns", plistCondJumpCommands);
    QListWidgetItem* plstItem_jcxz = new QListWidgetItem("jcxz", plistCondJumpCommands);


    QListWidget* plistCycleManageCommands = new QListWidget();
    QListWidgetItem* plstItem_loop = new QListWidgetItem("loop", plistCycleManageCommands);
    QListWidgetItem* plstItem_loope = new QListWidgetItem("loope", plistCycleManageCommands);
    QListWidgetItem* plstItem_loopz = new QListWidgetItem("loopz", plistCycleManageCommands);
    QListWidgetItem* plstItem_loopne = new QListWidgetItem("loopne", plistCycleManageCommands);
    QListWidgetItem* plstItem_loopnz = new QListWidgetItem("loopnz", plistCycleManageCommands);


    QListWidget* plistInterruptCommands = new QListWidget();
    QListWidgetItem* plstItem_int = new QListWidgetItem("int", plistInterruptCommands);
    QListWidgetItem* plstItem_into = new QListWidgetItem("into", plistInterruptCommands);


    QListWidget* plistFlagsCommands = new QListWidget();
    QListWidgetItem* plstItem_clc = new QListWidgetItem("clc", plistFlagsCommands);
    QListWidgetItem* plstItem_stc = new QListWidgetItem("stc", plistFlagsCommands);
    QListWidgetItem* plstItem_cmc = new QListWidgetItem("cmc", plistFlagsCommands);
    QListWidgetItem* plstItem_cld = new QListWidgetItem("cld", plistFlagsCommands);
    QListWidgetItem* plstItem_std = new QListWidgetItem("std", plistFlagsCommands);
    QListWidgetItem* plstItem_cli = new QListWidgetItem("cli", plistFlagsCommands);
    QListWidgetItem* plstItem_sti = new QListWidgetItem("sti", plistFlagsCommands);


    QListWidget* plistSpecialCommands = new QListWidget();
    QListWidgetItem* plstItem_hlt = new QListWidgetItem("hlt", plistSpecialCommands);
    QListWidgetItem* plstItem_wait = new QListWidgetItem("wait", plistSpecialCommands);
    QListWidgetItem* plstItem_lock = new QListWidgetItem("lock", plistSpecialCommands);
    QListWidgetItem* plstItem_esc = new QListWidgetItem("esc", plistSpecialCommands);
    QListWidgetItem* plstItem_nop = new QListWidgetItem("nop", plistSpecialCommands);

    m_ptoolCommandsPanel->addItem(plistMoveDataCommands, "Передача данных");
    m_ptoolCommandsPanel->addItem(plistSendFlagsCommands, "Пересылка флагов");
    m_ptoolCommandsPanel->addItem(plistStackCommands, "Стековые команды");
    m_ptoolCommandsPanel->addItem(plistIOCommands, "Ввод/вывод");
    m_ptoolCommandsPanel->addItem(plistAddingCommands, "Сложение");
    m_ptoolCommandsPanel->addItem(plistSubtractCommands, "Вычитание");
    m_ptoolCommandsPanel->addItem(plistMulDivCommands, "Умножение/деление");
    m_ptoolCommandsPanel->addItem(plistArithmOneOpCommands, "Арифметика с одним операндом");
    m_ptoolCommandsPanel->addItem(plistTransformCommands, "Преобразование");
    m_ptoolCommandsPanel->addItem(plistBinaryCorrectionCommands, "Десятичная коррекция");
    m_ptoolCommandsPanel->addItem(plistSymbolCorrectionCommands, "Символьная коррекция");
    m_ptoolCommandsPanel->addItem(plistLogicCommands, "Логические");
    m_ptoolCommandsPanel->addItem(plistShiftCommands, "Сдвиги");
    m_ptoolCommandsPanel->addItem(plistStringCommands, "Обработка строк");
    m_ptoolCommandsPanel->addItem(plistUncondJumpCommands, "Безусловные переходы");
    m_ptoolCommandsPanel->addItem(plistCondJumpCommands, "Условные переходы");
    m_ptoolCommandsPanel->addItem(plistCycleManageCommands, "Управление циклом");
    m_ptoolCommandsPanel->addItem(plistInterruptCommands, "Прерывания");
    m_ptoolCommandsPanel->addItem(plistFlagsCommands, "Установка флажков");
    m_ptoolCommandsPanel->addItem(plistBitsManageCommands, "Работа с битами");
    m_ptoolCommandsPanel->addItem(plistSpecialCommands, "Специальные");



    QVBoxLayout* pvblGeneral = new QVBoxLayout();
    pvblGeneral->addWidget(m_ptoolCommandsPanel);

    setLayout(pvblGeneral);
}
