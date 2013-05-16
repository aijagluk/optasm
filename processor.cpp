/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "processor.h"

GProcessor::GProcessor(QWidget *parent)
    :QWidget(parent){

    this->al = 0;
    this->ah = 0;
    this->ax = 0;
    this->eax = 0;
    this->bl = 0;
    this->bh = 0;
    this->bx = 0;
    this->ebx = 0;
    this->dl = 0;
    this->dh = 0;
    this->dx = 0;
    this->edx = 0;
    this->cl = 0;
    this->ch = 0;
    this->cx = 0;
    this->ecx = 0;

    this->bp = 0;
    this->ebp = 0;

    this->si = 0;
    this->esi = 0;

    this->di = 0;
    this->edi = 0;

    this->sp = 0;
    this->esp = 0;

    this->cs = 0;
    this->ds = 0;
    this->ss = 0;
    this->es = 0;
    this->fs = 0;
    this->gs = 0;

    this->cf = false;
    this->pf = false;
    this->af = false;
    this->zf = false;
    this->sf = false;
    this->of = false;
    this->iopl = false;
    this->nt = false;
    this->df = false;
    this->tf = false;
    this->_if = false;
    this->rf = false;
    this->vm = false;
    this->ac = false;

    this->ip = 0;
    this->eip = 0;

    this->pe = false;
    this->mp = true;    // !!true
    this->ts = false;
    this->am = false;
    this->cd = false;
    this->pg = false;

    this->cr1 = 0;      // !!0
    this->cr2 = 0;
    this->cr3 = 0;

    this->gdtr = 0;
    this->idtr = 0;
    this->ldtr = 0;
    this->_tr = 0;

    this->dr0 = 0;
    this->dr1 = 0;
    this->dr2 = 0;
    this->dr3 = 0;

    this->b0 = false;
    this->b1 = false;
    this->b2 = false;
    this->b3 = false;
    this->bd = false;
    this->bs = false;
    this->bt = false;

    this->dr7 = 0;

    /*USER REGISTERS*/
    /*accumulator registers*/
    this->m_al = new QLCDNumber(8);
    m_al->setSegmentStyle(QLCDNumber::Flat);
    m_al->setHexMode();
    m_al->setToolTip("8 бит");
    this->m_ah = new QLCDNumber(8);
    m_ah->setSegmentStyle(QLCDNumber::Flat);
    m_ah->setHexMode();
    m_ah->setToolTip("8 бит");
    this->m_ax = new QLCDNumber(8);
    m_ax->setSegmentStyle(QLCDNumber::Flat);
    m_ax->setHexMode();
    m_ax->setToolTip("16 бит");
    this->m_eax = new QLCDNumber(8);
    m_eax->setSegmentStyle(QLCDNumber::Flat);
    m_eax->setHexMode();
    m_eax->setToolTip("32 бита");

    /*base registers*/
    this->m_bl = new QLCDNumber(8);
    m_bl->setSegmentStyle(QLCDNumber::Flat);
    m_bl->setHexMode();
    m_bl->setToolTip("8 бит");
    this->m_bh = new QLCDNumber(8);
    m_bh->setSegmentStyle(QLCDNumber::Flat);
    m_bh->setHexMode();
    m_bh->setToolTip("8 бит");
    this->m_bx = new QLCDNumber(8);
    m_bx->setSegmentStyle(QLCDNumber::Flat);
    m_bx->setHexMode();
    m_bx->setToolTip("16 бит");
    this->m_ebx = new QLCDNumber(8);
    m_ebx->setSegmentStyle(QLCDNumber::Flat);
    m_ebx->setHexMode();
    m_ebx->setToolTip("32 бита");

    /*data registers*/
    this->m_dl = new QLCDNumber(8);
    m_dl->setSegmentStyle(QLCDNumber::Flat);
    m_dl->setHexMode();
    m_dl->setToolTip("8 бит");
    this->m_dh = new QLCDNumber(8);
    m_dh->setSegmentStyle(QLCDNumber::Flat);
    m_dh->setHexMode();
    m_dh->setToolTip("8 бит");
    this->m_dx = new QLCDNumber(8);
    m_dx->setSegmentStyle(QLCDNumber::Flat);
    m_dx->setHexMode();
    m_dx->setToolTip("16 бит");
    this->m_edx = new QLCDNumber(8);
    m_edx->setSegmentStyle(QLCDNumber::Flat);
    m_edx->setHexMode();
    m_edx->setToolTip("32 бита");

    /*count registers*/
    this->m_cl = new QLCDNumber(8);
    m_cl->setSegmentStyle(QLCDNumber::Flat);
    m_cl->setHexMode();
    m_cl->setToolTip("8 бит");
    this->m_ch = new QLCDNumber(8);
    m_ch->setSegmentStyle(QLCDNumber::Flat);
    m_ch->setHexMode();
    m_ch->setToolTip("8 бит");
    this->m_cx = new QLCDNumber(8);
    m_cx->setSegmentStyle(QLCDNumber::Flat);
    m_cx->setHexMode();
    m_cx->setToolTip("16 бит");
    this->m_ecx = new QLCDNumber(8);
    m_ecx->setSegmentStyle(QLCDNumber::Flat);
    m_ecx->setHexMode();
    m_ecx->setToolTip("32 бита");

    /*base pointer registers*/
    this->m_bp = new QLCDNumber(8);
    m_bp->setSegmentStyle(QLCDNumber::Flat);
    m_bp->setHexMode();
    m_bp->setToolTip("16 бит");
    this->m_ebp = new QLCDNumber(8);
    m_ebp->setSegmentStyle(QLCDNumber::Flat);
    m_ebp->setHexMode();
    m_ebp->setToolTip("32 бита");

    /*source index registers*/
    this->m_si = new QLCDNumber(8);
    m_si->setSegmentStyle(QLCDNumber::Flat);
    m_si->setHexMode();
    m_si->setToolTip("16 бит");
    this->m_esi = new QLCDNumber(8);
    m_esi->setSegmentStyle(QLCDNumber::Flat);
    m_esi->setHexMode();
    m_esi->setToolTip("32 бита");

    /*destination index registers*/
    this->m_di = new QLCDNumber(8);
    m_di->setSegmentStyle(QLCDNumber::Flat);
    m_di->setHexMode();
    m_di->setToolTip("16 бит");
    this->m_edi = new QLCDNumber(8);
    m_edi->setSegmentStyle(QLCDNumber::Flat);
    m_edi->setHexMode();
    m_edi->setToolTip("32 бита");

    /*stack pointer registers*/
    this->m_sp = new QLCDNumber(8);
    m_sp->setSegmentStyle(QLCDNumber::Flat);
    m_sp->setHexMode();
    m_sp->setToolTip("16 бит");
    this->m_esp = new QLCDNumber(8);
    m_esp->setSegmentStyle(QLCDNumber::Flat);
    m_esp->setHexMode();
    m_esp->setToolTip("32 бита");

    /*segment's registers*/
    this->m_cs = new QLCDNumber(8);  //code segment
    m_cs->setSegmentStyle(QLCDNumber::Flat);
    m_cs->setHexMode();
    m_cs->setToolTip("Code Segment (Сегмент кода) / 16 бит");
    this->m_ds = new QLCDNumber(8);  //data segment
    m_ds->setSegmentStyle(QLCDNumber::Flat);
    m_ds->setHexMode();
    m_ds->setToolTip("Data Segment (Сегмент данных) / 16 бит");
    this->m_ss = new QLCDNumber(8);  //stack segment
    m_ss->setSegmentStyle(QLCDNumber::Flat);
    m_ss->setHexMode();
    m_ss->setToolTip("Stack Segment (Стековый сегмент) / 16 бит");
    this->m_es = new QLCDNumber(8);  //extension data segments...
    m_es->setSegmentStyle(QLCDNumber::Flat);
    m_es->setHexMode();
    m_es->setToolTip("Extension data Segment (Расширенный сегмент данных) / 16 бит");
    this->m_fs = new QLCDNumber(8);  // =/=
    m_fs->setSegmentStyle(QLCDNumber::Flat);
    m_fs->setHexMode();
    m_fs->setToolTip("Дополнительный сегмент / 16 бит");
    this->m_gs = new QLCDNumber(8);  // =/=
    m_gs->setSegmentStyle(QLCDNumber::Flat);
    m_gs->setHexMode();
    m_gs->setToolTip("Дополнительный сегмент / 16 бит");

    /*flag register*/
    /*state flags*/
    this->m_cf = new QLCDNumber(1);   //curry flag
    m_cf->setSegmentStyle(QLCDNumber::Flat);
    m_cf->setToolTip("Флаг переноса");
    this->m_pf = new QLCDNumber(1);   //parity flag
    m_pf->setSegmentStyle(QLCDNumber::Flat);
    m_pf->setToolTip("Флаг четности");
    this->m_af = new QLCDNumber(1);   //auxiliary carry flag
    m_af->setSegmentStyle(QLCDNumber::Flat);
    m_af->setToolTip("Дополнительный флаг переноса");
    this->m_zf = new QLCDNumber(1);   //zero flag
    m_zf->setSegmentStyle(QLCDNumber::Flat);
    m_zf->setToolTip("Флаг нулевого результата");
    this->m_sf = new QLCDNumber(1);   //sign flag
    m_sf->setSegmentStyle(QLCDNumber::Flat);
    m_sf->setToolTip("Флаг знака результата");
    this->m_of = new QLCDNumber(1);   //overflow flag
    m_of->setSegmentStyle(QLCDNumber::Flat);
    m_of->setToolTip("Флаг переполнения");
    this->m_iopl = new QLCDNumber(1); //input/output privilege level
    m_iopl->setSegmentStyle(QLCDNumber::Flat);
    m_iopl->setToolTip("Текущий уровень привилегий ввода/вывода");
    this->m_nt = new QLCDNumber(1);   //nested task
    m_nt->setSegmentStyle(QLCDNumber::Flat);
    m_nt->setToolTip("Флаг вложенности задачи");

    this->m_df = new QLCDNumber(1);   //directory flag
    m_df->setSegmentStyle(QLCDNumber::Flat);
    m_df->setToolTip("Флаг направления");

    /*system flags*/
    this->m_tf = new QLCDNumber(1);   //trace flag
    m_tf->setSegmentStyle(QLCDNumber::Flat);
    m_tf->setToolTip("Флаг трассировки");
    this->m__if = new QLCDNumber(1);  //interrupt enable flag
    m__if->setSegmentStyle(QLCDNumber::Flat);
    m__if->setToolTip("Флаг разрешения прерывания");
    this->m_rf = new QLCDNumber(1);   //resume flag
    m_rf->setSegmentStyle(QLCDNumber::Flat);
    m_rf->setToolTip("Флаг возобновления");
    this->m_vm = new QLCDNumber(1);   //virtual 8086 mode
    m_vm->setSegmentStyle(QLCDNumber::Flat);
    m_vm->setToolTip("Флаг виртуального процессора 8086");
    this->m_ac = new QLCDNumber(1);   //alignment check
    m_ac->setSegmentStyle(QLCDNumber::Flat);
    m_ac->setToolTip("Флаг выравнивания адреса");

    /*!!!  В РЕАЛИЗАЦИИ ОТСУТСТВУЮТ ФЛАГИ VIP и ID   !!!*/

    /*instruction pointer register*/
    this->m_ip = new QLCDNumber(8);
    m_ip->setSegmentStyle(QLCDNumber::Flat);
    m_ip->setHexMode();
    m_ip->setToolTip("Instruction Pointer / 16 бит");
    this->m_eip = new QLCDNumber(8);
    m_eip->setSegmentStyle(QLCDNumber::Flat);
    m_eip->setHexMode();
    m_eip->setToolTip("Instruction Pointer / 32 бита");

    /*SYSTEM REGISTERS*/
    /*control registers*/
    /*cr0*/
    this->m_pe = new QLCDNumber(1);   //protect enable
    m_pe->setSegmentStyle(QLCDNumber::Flat);
    m_pe->setToolTip("Protect Enable (Control register)");
    this->m_mp = new QLCDNumber(1);   //math present !!true
    m_mp->setSegmentStyle(QLCDNumber::Flat);
    m_mp->setToolTip("Math Present (Control register)");
    this->m_ts = new QLCDNumber(1);   //task switched
    m_ts->setSegmentStyle(QLCDNumber::Flat);
    m_ts->setToolTip("Task Switched (Control register)");
    this->m_am = new QLCDNumber(1);   //alignment mask
    m_am->setSegmentStyle(QLCDNumber::Flat);
    m_am->setToolTip("Alignment Mask (Control register)");
    this->m_cd = new QLCDNumber(1);   //cache disable
    m_cd->setSegmentStyle(QLCDNumber::Flat);
    m_cd->setToolTip("Cache Disable (Control register)");
    this->m_pg = new QLCDNumber(1);   //paging
    m_pg->setSegmentStyle(QLCDNumber::Flat);
    m_pg->setToolTip("Paging (Control register)");

//    this->m_cr1 = new QLCDNumber(8); //must be disable
//    m_cr1->setSegmentStyle(QLCDNumber::Flat);
//    m_cr1->setHexMode();
    this->m_cr2 = new QLCDNumber(8);
    m_cr2->setSegmentStyle(QLCDNumber::Flat);
    m_cr2->setHexMode();
    m_cr2->setToolTip("Control register (Управляющий регистр) / 32 бита");
    this->m_cr3 = new QLCDNumber(8);
    m_cr3->setSegmentStyle(QLCDNumber::Flat);
    m_cr3->setHexMode();
    m_cr3->setToolTip("Control register (Управляющий регистр) / 32 бита");

    this->m_gdtr = new QLCDNumber(16);    //global descriptor table register
    m_gdtr->setSegmentStyle(QLCDNumber::Flat);
    m_gdtr->setHexMode();
    m_gdtr->setToolTip("Global Descriptor Table Register / 32 бита");
    this->m_idtr = new QLCDNumber(16);    //interrupt descriptor table register
    m_idtr->setSegmentStyle(QLCDNumber::Flat);
    m_idtr->setHexMode();
    m_idtr->setToolTip("Interrupt Descriptor Table Register / 32 бита");
    this->m_ldtr = new QLCDNumber(16);    //local descriptor table register
    m_ldtr->setSegmentStyle(QLCDNumber::Flat);
    m_ldtr->setHexMode();
    m_ldtr->setToolTip("Local Descriptor Table Register / 32 бита");
    this->m__tr = new QLCDNumber(8);      //task register
    m__tr->setSegmentStyle(QLCDNumber::Flat);
    m__tr->setHexMode();
    m__tr->setToolTip("Task Register / 32 бита");

    /*debug registers*/
    this->m_dr0 = new QLCDNumber(8);
    m_dr0->setSegmentStyle(QLCDNumber::Flat);
    m_dr0->setHexMode();
    m_dr0->setToolTip("Debug Register 0 / 32 бита");

    this->m_dr1 = new QLCDNumber(8);
    m_dr1->setSegmentStyle(QLCDNumber::Flat);
    m_dr1->setHexMode();
    m_dr1->setToolTip("Debug Register 1 / 32 бита");
    this->m_dr2 = new QLCDNumber(8);
    m_dr2->setSegmentStyle(QLCDNumber::Flat);
    m_dr2->setHexMode();
    m_dr2->setToolTip("Debug Register 2 / 32 бита");
    this->m_dr3 = new QLCDNumber(8);
    m_dr3->setSegmentStyle(QLCDNumber::Flat);
    m_dr3->setHexMode();
    m_dr3->setToolTip("Debug Register 3 / 32 бита");

    /*dr6*/
    this->m_b0 = new QLCDNumber(1);
    m_b0->setSegmentStyle(QLCDNumber::Flat);
    m_b0->setToolTip("Bit of Debug Register 6");
    this->m_b1 = new QLCDNumber(1);
    m_b1->setSegmentStyle(QLCDNumber::Flat);
    m_b1->setToolTip("Bit of Debug Register 6");
    this->m_b2 = new QLCDNumber(1);
    m_b2->setSegmentStyle(QLCDNumber::Flat);
    m_b2->setToolTip("Bit of Debug Register 6");
    this->m_b3 = new QLCDNumber(1);
    m_b3->setSegmentStyle(QLCDNumber::Flat);
    m_b3->setToolTip("Bit of Debug Register 6");
    this->m_bd = new QLCDNumber(1);
    m_bd->setSegmentStyle(QLCDNumber::Flat);
    m_bd->setToolTip("Bit of Debug Register 6");
    this->m_bs = new QLCDNumber(1);
    m_bs->setSegmentStyle(QLCDNumber::Flat);
    m_bs->setToolTip("Bit of Debug Register 6");
    this->m_bt = new QLCDNumber(1);
    m_bt->setSegmentStyle(QLCDNumber::Flat);
    m_bt->setToolTip("Bit of Debug Register 6");

    this->m_dr7 = new QLCDNumber(8);
    m_dr7->setSegmentStyle(QLCDNumber::Flat);
    m_dr7->setHexMode();
    m_dr7->setToolTip("Debug Register 7 / 32 бита");


    //to build the UI after initialization
    buildUI();
}

void GProcessor::buildUI(void){
    QGroupBox* pgbAccumulatorRegs = new QGroupBox("Аккумулятор");
    QGridLayout* pglAccumulatorRegs = new QGridLayout();
    QLabel* plblAl = new QLabel("al");
    QLabel* plblAh = new QLabel("ah");
    QLabel* plblAx = new QLabel("ax");
    QLabel* plblEax = new QLabel("eax");
    pglAccumulatorRegs->addWidget(plblAl, 0, 0);
    pglAccumulatorRegs->addWidget(m_al, 0, 1);
    pglAccumulatorRegs->addWidget(plblAh, 1, 0);
    pglAccumulatorRegs->addWidget(m_ah, 1, 1);
    pglAccumulatorRegs->addWidget(plblAx, 2, 0);
    pglAccumulatorRegs->addWidget(m_ax, 2, 1);
    pglAccumulatorRegs->addWidget(plblEax, 3, 0);
    pglAccumulatorRegs->addWidget(m_eax, 3, 1);
    pgbAccumulatorRegs->setLayout(pglAccumulatorRegs);

    QGroupBox* pgbBaseRegs = new QGroupBox("Базовый регистр");
    QGridLayout* pglBaseRegs = new QGridLayout();
    QLabel* plblBl = new QLabel("bl");
    QLabel* plblBh = new QLabel("bh");
    QLabel* plblBx = new QLabel("bx");
    QLabel* plblEbx = new QLabel("ebx");
    pglBaseRegs->addWidget(plblBl, 0, 0);
    pglBaseRegs->addWidget(m_bl, 0, 1);
    pglBaseRegs->addWidget(plblBh, 1, 0);
    pglBaseRegs->addWidget(m_bh, 1, 1);
    pglBaseRegs->addWidget(plblBx, 2, 0);
    pglBaseRegs->addWidget(m_bx, 2, 1);
    pglBaseRegs->addWidget(plblEbx, 3, 0);
    pglBaseRegs->addWidget(m_ebx, 3, 1);
    pgbBaseRegs->setLayout(pglBaseRegs);

    QGroupBox* pgbCountRegs = new QGroupBox("Счетчик");
    QGridLayout* pglCountRegs = new QGridLayout();
    QLabel* plblCl = new QLabel("cl");
    QLabel* plblCh = new QLabel("ch");
    QLabel* plblCx = new QLabel("cx");
    QLabel* plblEcx = new QLabel("ecx");
    pglCountRegs->addWidget(plblCl, 0, 0);
    pglCountRegs->addWidget(m_cl, 0, 1);
    pglCountRegs->addWidget(plblCh, 1, 0);
    pglCountRegs->addWidget(m_ch, 1, 1);
    pglCountRegs->addWidget(plblCx, 2, 0);
    pglCountRegs->addWidget(m_cx, 2, 1);
    pglCountRegs->addWidget(plblEcx, 3, 0);
    pglCountRegs->addWidget(m_ecx, 3, 1);
    pgbCountRegs->setLayout(pglCountRegs);

    QGroupBox* pgbDataRegs = new QGroupBox("Регистр данных");
    QGridLayout* pglDataRegs = new QGridLayout();
    QLabel* plblDl = new QLabel("dl");
    QLabel* plblDh = new QLabel("dh");
    QLabel* plblDx = new QLabel("dx");
    QLabel* plblEdx = new QLabel("edx");
    pglDataRegs->addWidget(plblDl, 0, 0);
    pglDataRegs->addWidget(m_dl, 0, 1);
    pglDataRegs->addWidget(plblDh, 1, 0);
    pglDataRegs->addWidget(m_dh, 1, 1);
    pglDataRegs->addWidget(plblDx, 2, 0);
    pglDataRegs->addWidget(m_dx, 2, 1);
    pglDataRegs->addWidget(plblEdx, 3, 0);
    pglDataRegs->addWidget(m_edx, 3, 1);
    pgbDataRegs->setLayout(pglDataRegs);

    QGroupBox* pgbBasePointerRegs = new QGroupBox("Указатель базы кадра стека");
    QGridLayout* pglBasePointerRegs = new QGridLayout();
    QLabel* plblBp = new QLabel("bp");
    QLabel* plblEbp = new QLabel("ebp");
    pglBasePointerRegs->addWidget(plblBp, 0, 0);
    pglBasePointerRegs->addWidget(m_bp, 0, 1);
    pglBasePointerRegs->addWidget(plblEbp, 1, 0);
    pglBasePointerRegs->addWidget(m_ebp, 1, 1);
    pgbBasePointerRegs->setLayout(pglBasePointerRegs);

    QGroupBox* pgbSourceIndexRegs = new QGroupBox("Индекс источника");
    QGridLayout* pglSourceIndexRegs = new QGridLayout();
    QLabel* plblSi = new QLabel("si");
    QLabel* plblEsi = new QLabel("esi");
    pglSourceIndexRegs->addWidget(plblSi, 0, 0);
    pglSourceIndexRegs->addWidget(m_si, 0, 1);
    pglSourceIndexRegs->addWidget(plblEsi, 1, 0);
    pglSourceIndexRegs->addWidget(m_esi, 1, 1);
    pgbSourceIndexRegs->setLayout(pglSourceIndexRegs);

    QGroupBox* pgbDestIndexRegs = new QGroupBox("Индекс приемника");
    QGridLayout* pglDestIndexRegs = new QGridLayout();
    QLabel* plblDi = new QLabel("di");
    QLabel* plblEdi = new QLabel("edi");
    pglDestIndexRegs->addWidget(plblDi, 0, 0);
    pglDestIndexRegs->addWidget(m_di, 0, 1);
    pglDestIndexRegs->addWidget(plblEdi, 1, 0);
    pglDestIndexRegs->addWidget(m_edi, 1, 1);
    pgbDestIndexRegs->setLayout(pglDestIndexRegs);

    QGroupBox* pgbStackPointerRegs = new QGroupBox("Указатель стека");
    QGridLayout* pglStackPointerRegs = new QGridLayout();
    QLabel* plblSp = new QLabel("sp");
    QLabel* plblEsp = new QLabel("esp");
    pglStackPointerRegs->addWidget(plblSp, 0, 0);
    pglStackPointerRegs->addWidget(m_sp, 0, 1);
    pglStackPointerRegs->addWidget(plblEsp, 1, 0);
    pglStackPointerRegs->addWidget(m_esp, 1, 1);
    pgbStackPointerRegs->setLayout(pglStackPointerRegs);

    QGroupBox* pgbSegmentRegs = new QGroupBox("Сегментные регистры");
    QGridLayout* pglSegmentRegs = new QGridLayout();
    QLabel* plblCs = new QLabel("cs");
    QLabel* plblDs = new QLabel("ds");
    QLabel* plblSs = new QLabel("ss");
    QLabel* plblEs = new QLabel("es");
    QLabel* plblFs = new QLabel("fs");
    QLabel* plblGs = new QLabel("gs");
    pglSegmentRegs->addWidget(plblCs, 0, 0);
    pglSegmentRegs->addWidget(m_cs, 0, 1);
    pglSegmentRegs->addWidget(plblDs, 1, 0);
    pglSegmentRegs->addWidget(m_ds, 1, 1);
    pglSegmentRegs->addWidget(plblSs, 2, 0);
    pglSegmentRegs->addWidget(m_ss, 2, 1);
    pglSegmentRegs->addWidget(plblEs, 3, 0);
    pglSegmentRegs->addWidget(m_es, 3, 1);
    pglSegmentRegs->addWidget(plblFs, 4, 0);
    pglSegmentRegs->addWidget(m_fs, 4, 1);
    pglSegmentRegs->addWidget(plblGs, 5, 0);
    pglSegmentRegs->addWidget(m_gs, 5, 1);
    pgbSegmentRegs->setLayout(pglSegmentRegs);

    QGroupBox* pgbInstructionPointerRegs = new QGroupBox("Указатель команд");
    QGridLayout* pglInstructionPointerRegs = new QGridLayout();
    QLabel* plblIp = new QLabel("ip");
    QLabel* plblEip = new QLabel("eip");
    pglInstructionPointerRegs->addWidget(plblIp, 0, 0);
    pglInstructionPointerRegs->addWidget(m_ip, 0, 1);
    pglInstructionPointerRegs->addWidget(plblEip, 1, 0);
    pglInstructionPointerRegs->addWidget(m_eip, 1, 1);
    pgbInstructionPointerRegs->setLayout(pglInstructionPointerRegs);

    QGroupBox* pgbFlagRegs = new QGroupBox("Флаговый регистр");
    QGridLayout* pglFlagRegs = new QGridLayout();
    QLabel* plblCf = new QLabel("cf");
    QLabel* plblPf = new QLabel("pf");
    QLabel* plblAf = new QLabel("af");
    QLabel* plblZf = new QLabel("zf");
    QLabel* plblSf = new QLabel("sf");
    QLabel* plblOf = new QLabel("of");
    QLabel* plblIopl = new QLabel("iopl");
    QLabel* plblNt = new QLabel("nt");
    QLabel* plblDf = new QLabel("df");
    QLabel* plblTf = new QLabel("tf");
    QLabel* plbl_if = new QLabel("if");
    QLabel* plblRf = new QLabel("rf");
    QLabel* plblVm = new QLabel("vm");
    QLabel* plblAc = new QLabel("ac");
    pglFlagRegs->addWidget(plblCf, 0, 0);
    pglFlagRegs->addWidget(m_cf, 0, 1);
    pglFlagRegs->addWidget(plblPf, 1, 0);
    pglFlagRegs->addWidget(m_pf, 1, 1);
    pglFlagRegs->addWidget(plblAf, 2, 0);
    pglFlagRegs->addWidget(m_af, 2, 1);
    pglFlagRegs->addWidget(plblZf, 3, 0);
    pglFlagRegs->addWidget(m_zf, 3, 1);
    pglFlagRegs->addWidget(plblSf, 4, 0);
    pglFlagRegs->addWidget(m_sf, 4, 1);
    pglFlagRegs->addWidget(plblOf, 5, 0);
    pglFlagRegs->addWidget(m_of, 5, 1);
    pglFlagRegs->addWidget(plblIopl, 6, 0);
    pglFlagRegs->addWidget(m_iopl, 6, 1);
    pglFlagRegs->addWidget(plblNt, 7, 0);
    pglFlagRegs->addWidget(m_nt, 7, 1);
    pglFlagRegs->addWidget(plblDf, 8, 0);
    pglFlagRegs->addWidget(m_df, 8, 1);
    pglFlagRegs->addWidget(plblTf, 9, 0);
    pglFlagRegs->addWidget(m_tf, 9, 1);
    pglFlagRegs->addWidget(plbl_if, 10, 0);
    pglFlagRegs->addWidget(m__if, 10, 1);
    pglFlagRegs->addWidget(plblRf, 11, 0);
    pglFlagRegs->addWidget(m_rf, 11, 1);
    pglFlagRegs->addWidget(plblVm, 12, 0);
    pglFlagRegs->addWidget(m_vm, 12, 1);
    pglFlagRegs->addWidget(plblAc, 13, 0);
    pglFlagRegs->addWidget(m_ac, 13, 1);
    pgbFlagRegs->setLayout(pglFlagRegs);

    QGroupBox* pgbDebugRegs = new QGroupBox("Отладочные регистры");
    QGridLayout* pglDebugRegs = new QGridLayout();
    QLabel* plblDr0 = new QLabel("dr0");
    QLabel* plblDr1 = new QLabel("dr1");
    QLabel* plblDr2 = new QLabel("dr2");
    QLabel* plblDr3 = new QLabel("dr3");
    QLabel* plblB0 = new QLabel("b0");
    QLabel* plblB1 = new QLabel("b1");
    QLabel* plblB2 = new QLabel("b2");
    QLabel* plblB3 = new QLabel("b3");
    QLabel* plblBd = new QLabel("bd");
    QLabel* plblBs = new QLabel("bs");
    QLabel* plblBt = new QLabel("bt");
    QLabel* plblDr7 = new QLabel("dr7");
    pglDebugRegs->addWidget(plblDr0, 0, 0);
    pglDebugRegs->addWidget(m_dr0, 0, 1);
    pglDebugRegs->addWidget(plblDr1, 1, 0);
    pglDebugRegs->addWidget(m_dr1, 1, 1);
    pglDebugRegs->addWidget(plblDr2, 2, 0);
    pglDebugRegs->addWidget(m_dr2, 2, 1);
    pglDebugRegs->addWidget(plblDr3, 3, 0);
    pglDebugRegs->addWidget(m_dr3, 3, 1);
    pglDebugRegs->addWidget(plblB0, 4, 0);
    pglDebugRegs->addWidget(m_b0, 4, 1);
    pglDebugRegs->addWidget(plblB1, 5, 0);
    pglDebugRegs->addWidget(m_b1, 5, 1);
    pglDebugRegs->addWidget(plblB2, 6, 0);
    pglDebugRegs->addWidget(m_b2, 6, 1);
    pglDebugRegs->addWidget(plblB3, 7, 0);
    pglDebugRegs->addWidget(m_b3, 7, 1);
    pglDebugRegs->addWidget(plblBd, 8, 0);
    pglDebugRegs->addWidget(m_bd, 8, 1);
    pglDebugRegs->addWidget(plblBs, 9, 0);
    pglDebugRegs->addWidget(m_bs, 9, 1);
    pglDebugRegs->addWidget(plblBt, 10, 0);
    pglDebugRegs->addWidget(m_bt, 10, 1);
    pglDebugRegs->addWidget(plblDr7, 11, 0);
    pglDebugRegs->addWidget(m_dr7, 11, 1);
    pgbDebugRegs->setLayout(pglDebugRegs);

    QGroupBox* pgbSystemRegs = new QGroupBox("Системные регистры");
    QGridLayout* pglSystemRegs = new QGridLayout();
    QLabel* plblPe = new QLabel("pe");
    QLabel* plblMp = new QLabel("mp");
    QLabel* plblTs = new QLabel("ts");
    QLabel* plblAm = new QLabel("am");
    QLabel* plblCd = new QLabel("cd");
    QLabel* plblPg = new QLabel("pg");
    //QLabel* plblCr1 = new QLabel("cr1");
    QLabel* plblCr2 = new QLabel("cr2");
    QLabel* plblCr3 = new QLabel("cr3");
    QLabel* plblGdtr = new QLabel("gdtr");
    QLabel* plblIdtr = new QLabel("idtr");
    QLabel* plblLdtr = new QLabel("ldtr");
    QLabel* plbl_tr = new QLabel("tr");
    pglSystemRegs->addWidget(plblPe, 0, 0);
    pglSystemRegs->addWidget(m_pe, 0, 1);
    pglSystemRegs->addWidget(plblMp, 1, 0);
    pglSystemRegs->addWidget(m_mp, 1, 1);
    pglSystemRegs->addWidget(plblTs, 2, 0);
    pglSystemRegs->addWidget(m_ts, 2, 1);
    pglSystemRegs->addWidget(plblAm, 3, 0);
    pglSystemRegs->addWidget(m_am, 3, 1);
    pglSystemRegs->addWidget(plblCd, 4, 0);
    pglSystemRegs->addWidget(m_cd, 4, 1);
    pglSystemRegs->addWidget(plblPg, 5, 0);
    pglSystemRegs->addWidget(m_pg, 5, 1);
    //pglSystemRegs->addWidget(plblCr1, 0, 2);
    //pglSystemRegs->addWidget(m_cr1, 0, 3);
    pglSystemRegs->addWidget(plbl_tr, 0, 2);
    pglSystemRegs->addWidget(m__tr, 0, 3);
    pglSystemRegs->addWidget(plblCr2, 1, 2);
    pglSystemRegs->addWidget(m_cr2, 1, 3);
    pglSystemRegs->addWidget(plblCr3, 2, 2);
    pglSystemRegs->addWidget(m_cr3, 2, 3);
    pglSystemRegs->addWidget(plblGdtr, 3, 2);
    pglSystemRegs->addWidget(m_gdtr, 3, 3);
    pglSystemRegs->addWidget(plblIdtr, 4, 2);
    pglSystemRegs->addWidget(m_idtr, 4, 3);
    pglSystemRegs->addWidget(plblLdtr, 5, 2);
    pglSystemRegs->addWidget(m_ldtr, 5, 3);
    //pglSystemRegs->addWidget(plbl_tr, 6, 0);
    //pglSystemRegs->addWidget(m__tr, 6, 1);
    pgbSystemRegs->setLayout(pglSystemRegs);

    QGridLayout* pglGeneral = new QGridLayout();
    pglGeneral->addWidget(pgbAccumulatorRegs, 0, 0);
    pglGeneral->addWidget(pgbBaseRegs, 0, 1);
    pglGeneral->addWidget(pgbCountRegs, 0, 2);
    pglGeneral->addWidget(pgbDataRegs, 0, 3);
    pglGeneral->addWidget(pgbFlagRegs, 0, 4, 4, 1);
    pglGeneral->addWidget(pgbDebugRegs, 0, 5, 4, 1);
    pglGeneral->addWidget(pgbBasePointerRegs, 1, 0);
    pglGeneral->addWidget(pgbSourceIndexRegs, 1, 1);
    pglGeneral->addWidget(pgbDestIndexRegs, 1, 2);
    pglGeneral->addWidget(pgbStackPointerRegs, 1, 3);
    pglGeneral->addWidget(pgbSegmentRegs, 2, 0, 2, 1);
    pglGeneral->addWidget(pgbSystemRegs, 2, 1, 2, 2);
    pglGeneral->addWidget(pgbInstructionPointerRegs, 2, 3);

    this->setLayout(pglGeneral);
}

void GProcessor::updateRegisters(){
    //int tmp;

    m_al->display(getAL());
    m_ah->display(getAH());
    m_ax->display(getAX());
    m_eax->display(getEAX());

    m_bl->display(getBL());
    m_bh->display(getBH());
    m_bx->display(getBX());
    m_ebx->display(getEBX());

    m_cl->display(getCL());
    m_ch->display(getCH());
    m_cx->display(getCX());
    m_ecx->display(getECX());

    m_dl->display(getDL());
    m_dh->display(getDH());
    m_dx->display(getDX());
    m_edx->display(getEDX());

    m_bp->display(getBP());
    m_ebp->display(getEBP());

    m_si->display(getSI());
    m_esi->display(getESI());

    m_di->display(getDI());
    m_edi->display(getEDI());

    m_sp->display(getSP());
    m_esp->display(getESP());

    m_cs->display(getCS());
    m_ds->display(getDS());
    m_ss->display(getSS());
    m_es->display(getES());
    m_fs->display(getFS());
    m_gs->display(getGS());

    m_cf->display(getCF());
    m_pf->display(getPF());
    m_af->display(getAF());
    m_zf->display(getZF());
    m_sf->display(getSF());
    m_of->display(getOF());
    m_iopl->display(getIOPL());
    m_nt->display(getNT());
    m_df->display(getDF());
    m_tf->display(getTF());
    m__if->display(getIF());
    m_rf->display(getRF());
    m_vm->display(getVM());
    m_ac->display(getAC());

    m_ip->display(getIP());
    m_eip->display(getEIP());

    m_pe->display(getPE());
    m_mp->display(getMP());
    m_ts->display(getTS());
    m_am->display(getAM());
    m_cd->display(getCD());
    m_pg->display(getPG());

    //m_cr1->display(getCR);
    //m_cr1->setEnabled(false);
    m_cr2->display(getCR2());
    m_cr3->display(getCR3());

    /*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/
    //m_gdtr->display(gdtr);
    m_gdtr->setEnabled(false);
    //m_idtr->display(idtr);
    m_idtr->setEnabled(false);
    m_ldtr->display(getLDTR());
    m__tr->display(getTR());

    m_dr0->display(getDR0());
    m_dr1->display(getDR1());
    m_dr2->display(getDR2());
    m_dr3->display(getDR3());

    m_b0->display(getB0());
    m_b1->display(getB1());
    m_b2->display(getB2());
    m_b3->display(getB3());
    m_bd->display(getBD());
    m_bs->display(getBS());
    m_bt->display(getBT());

    m_dr7->display(getDR7());

    this->repaint();

}
