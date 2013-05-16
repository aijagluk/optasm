/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/


#ifndef PROCESSOR_H
#define PROCESSOR_H

#include <QtGui>
#include <QtWidgets/QWidget>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>


class GProcessor : public QWidget{
        Q_OBJECT
private:
        /*USER REGISTERS*/
        /*accumulator registers*/
        qint8 al;
        qint8 ah;
        qint16 ax;
        qint32 eax;

        /*base registers*/
        qint8 bl;
        qint8 bh;
        qint16 bx;
        qint32 ebx;

        /*data registers*/
        qint8 dl;
        qint8 dh;
        qint16 dx;
        qint32 edx;

        /*count registers*/
        qint8 cl;
        qint8 ch;
        qint16 cx;
        qint32 ecx;

        /*base pointer registers*/
        qint16 bp;
        qint32 ebp;

        /*source index registers*/
        qint16 si;
        qint32 esi;

        /*destination index registers*/
        qint16 di;
        qint32 edi;

        /*stack pointer registers*/
        qint16 sp;
        qint32 esp;

        /*segment's registers*/
        qint16 cs;  //code segment
        qint16 ds;  //data segment
        qint16 ss;  //stack segment
        qint16 es;  //extension data segments...
        qint16 fs;  // =/=
        qint16 gs;  // =/=

        /*flag register*/
        /*state flags*/
        bool cf;   //curry flag
        bool pf;   //parity flag
        bool af;   //auxiliary carry flag
        bool zf;   //zero flag
        bool sf;   //sign flag
        bool of;   //overflow flag
        bool iopl; //input/output privilege level
        bool nt;   //nested task

        bool df;   //directory flag

        /*system flags*/
        bool tf;   //trace flag
        bool _if;  //interrupt enable flag
        bool rf;   //resume flag
        bool vm;   //virtual 8086 mode
        bool ac;   //alignment check

        /*instruction pointer register*/
        qint16 ip;
        qint32 eip;

        /*SYSTEM REGISTERS*/
        /*control registers*/
        /*cr0*/
        bool pe;   //protect enable
        bool mp;   //math present !!true
        bool ts;   //task switched
        bool am;   //alignment mask
        bool cd;   //cache disable
        bool pg;   //paging

        qint32 cr1; //must be disable
        qint32 cr2;
        qint32 cr3;

        qint64 gdtr;    //global descriptor table register
        qint64 idtr;    //interrupt descriptor table register
        qint16 ldtr;    //local descriptor table register
        qint16 _tr;      //task register

        /*debug registers*/
        qint32 dr0;
        qint32 dr1;
        qint32 dr2;
        qint32 dr3;

        /*dr6*/
        bool b0;
        bool b1;
        bool b2;
        bool b3;
        bool bd;
        bool bs;
        bool bt;

        qint32 dr7;

        /*Tick Counter*/
        quint64 m_tickCounter;

        /*----------------WIDGETS FOR DISPLAYING VALUES OF REGISTERS----------------*/

        /*USER REGISTERS*/
        /*accumulator registers*/
        QLCDNumber* m_al;
        QLCDNumber* m_ah;
        QLCDNumber* m_ax;
        QLCDNumber* m_eax;

        /*base registers*/
        QLCDNumber* m_bl;
        QLCDNumber* m_bh;
        QLCDNumber* m_bx;
        QLCDNumber* m_ebx;

        /*data registers*/
        QLCDNumber* m_dl;
        QLCDNumber* m_dh;
        QLCDNumber* m_dx;
        QLCDNumber* m_edx;

        /*count registers*/
        QLCDNumber* m_cl;
        QLCDNumber* m_ch;
        QLCDNumber* m_cx;
        QLCDNumber* m_ecx;

        /*base pointer registers*/
        QLCDNumber* m_bp;
        QLCDNumber* m_ebp;

        /*source index registers*/
        QLCDNumber* m_si;
        QLCDNumber* m_esi;

        /*destination index registers*/
        QLCDNumber* m_di;
        QLCDNumber* m_edi;

        /*stack pointer registers*/
        QLCDNumber* m_sp;
        QLCDNumber* m_esp;

        /*segment's registers*/
        QLCDNumber* m_cs;  //code segment
        QLCDNumber* m_ds;  //data segment
        QLCDNumber* m_ss;  //stack segment
        QLCDNumber* m_es;  //extension data segments...
        QLCDNumber* m_fs;  // =/=
        QLCDNumber* m_gs;  // =/=

        /*flag register*/
        /*state flags*/
        QLCDNumber* m_cf;   //curry flag
        QLCDNumber* m_pf;   //parity flag
        QLCDNumber* m_af;   //auxiliary carry flag
        QLCDNumber* m_zf;   //zero flag
        QLCDNumber* m_sf;   //sign flag
        QLCDNumber* m_of;   //overflow flag
        QLCDNumber* m_iopl; //input/output privilege level
        QLCDNumber* m_nt;   //nested task

        QLCDNumber* m_df;   //directory flag

        /*system flags*/
        QLCDNumber* m_tf;   //trace flag
        QLCDNumber* m__if;  //interrupt enable flag
        QLCDNumber* m_rf;   //resume flag
        QLCDNumber* m_vm;   //virtual 8086 mode
        QLCDNumber* m_ac;   //alignment check

        /*instruction pointer register*/
        QLCDNumber* m_ip;
        QLCDNumber* m_eip;

        /*SYSTEM REGISTERS*/
        /*control registers*/
        /*cr0*/
        QLCDNumber* m_pe;   //protect enable
        QLCDNumber* m_mp;   //math present !!true
        QLCDNumber* m_ts;   //task switched
        QLCDNumber* m_am;   //alignment mask
        QLCDNumber* m_cd;   //cache disable
        QLCDNumber* m_pg;   //paging

        //QLCDNumber* m_cr1; //must be disable
        QLCDNumber* m_cr2;
        QLCDNumber* m_cr3;

        QLCDNumber* m_gdtr;    //global descriptor table register
        QLCDNumber* m_idtr;    //interrupt descriptor table register
        QLCDNumber* m_ldtr;    //local descriptor table register
        QLCDNumber* m__tr;      //task register

        /*debug registers*/
        QLCDNumber* m_dr0;
        QLCDNumber* m_dr1;
        QLCDNumber* m_dr2;
        QLCDNumber* m_dr3;

        /*dr6*/
        QLCDNumber* m_b0;
        QLCDNumber* m_b1;
        QLCDNumber* m_b2;
        QLCDNumber* m_b3;
        QLCDNumber* m_bd;
        QLCDNumber* m_bs;
        QLCDNumber* m_bt;

        QLCDNumber* m_dr7;


public:
        explicit GProcessor(QWidget *parent = 0);

        /*-----------ACCESSORS------------*/

        qint8  getAL(void)  const{
                return(this->al);
        }
        qint8  getAH(void)  const{
                return(this->ah);
        }
        qint16 getAX(void)  const{
                return(this->ax);
        }
        qint32 getEAX(void) const{
                return(this->eax);
        }

        qint8  getBL(void)  const{
                return(this->bl);
        }
        qint8  getBH(void)  const{
                return(this->bh);
        }
        qint16 getBX(void)  const{
                return(this->bx);
        }
        qint32 getEBX(void) const{
                return(this->ebx);
        }

        qint8  getDL(void)  const{
                return(this->dl);
        }
        qint8  getDH(void)  const{
                return(this->dh);
        }
        qint16 getDX(void)  const{
                return(this->dx);
        }
        qint32 getEDX(void) const{
                return(this->edx);
        }

        qint8  getCL(void)  const{
                return(this->cl);
        }
        qint8  getCH(void)  const{
                return(this->ch);
        }
        qint16 getCX(void)  const{
                return(this->cx);
        }
        qint32 getECX(void) const{
                return(this->ecx);
        }

        qint16 getBP(void) const{
                return(this->bp);
        }
        qint32 getEBP(void) const{
                return(this->ebp);
        }

        qint16 getSI(void) const{
                return(this->si);
        }
        qint32 getESI(void) const{
                return(this->esi);
        }

        qint16 getDI(void) const{
                return(this->di);
        }
        qint32 getEDI(void) const{
                return(this->edi);
        }

        qint16 getSP(void) const{
                return(this->sp);
        }
        qint32 getESP(void) const{
                return(this->esp);
        }

        qint16 getCS(void) const{
                return(this->cs);
        }
        qint16 getDS(void) const{
                return(this->ds);
        }
        qint16 getSS(void) const{
                return(this->ss);
        }
        qint16 getES(void) const{
                return(this->es);
        }
        qint16 getFS(void) const{
                return(this->fs);
        }
        qint16 getGS(void) const{
                return(this->gs);
        }

        bool getCF(void) const{
                return(this->cf);
        }
        bool getPF(void) const{
                return(this->pf);
        }
        bool getAF(void) const{
                return(this->af);
        }
        bool getZF(void) const{
                return(this->zf);
        }
        bool getSF(void) const{
                return(this->sf);
        }
        bool getOF(void) const{
                return(this->of);
        }
        bool getIOPL(void) const{
                return(this->iopl);
        }
        bool getNT(void) const{
                return(this->nt);
        }
        bool getDF(void) const{
                return(this->df);
        }
        bool getTF(void) const{
                return(this->tf);
        }
        bool getIF(void) const{
                return(this->_if);
        }
        bool getRF(void) const{
                return(this->rf);
        }
        bool getVM(void) const{
                return(this->vm);
        }
        bool getAC(void) const{
                return(this->ac);
        }

        qint16 getIP(void) const{
                return(this->ip);
        }
        qint32 getEIP(void) const{
                return(this->eip);
        }

        bool getPE(void) const{
                return(this->pe);
        }
        bool getMP(void) const{
                return(this->mp);
        }
        bool getTS(void) const{
                return(this->ts);
        }
        bool getAM(void) const{
                return(this->am);
        }
        bool getCD(void) const{
                return(this->cd);
        }
        bool getPG(void) const{
                return(this->pg);
        }

        qint32 getCR2(void) const{
                return(this->cr2);
        }
        qint32 getCR3(void) const{
                return(this->cr3);
        }

        qint64 getGDTR(void) const{
                return(this->gdtr);
        }
        qint64 getIDTR(void) const{
                return(this->idtr);
        }
        qint16 getLDTR(void) const{
                return(this->ldtr);
        }
        qint16 getTR(void) const{
                return(this->_tr);
        }

        qint32 getDR0(void) const{
                return(this->dr0);
        }
        qint32 getDR1(void) const{
                return(this->dr1);
        }
        qint32 getDR2(void) const{
                return(this->dr2);
        }
        qint32 getDR3(void) const{
                return(this->dr3);
        }

        bool getB0(void) const{
                return(this->b0);
        }
        bool getB1(void) const{
                return(this->b1);
        }
        bool getB2(void) const{
                return(this->b2);
        }
        bool getB3(void) const{
                return(this->b3);
        }
        bool getBD(void) const{
                return(this->bd);
        }
        bool getBS(void) const{
                return(this->bs);
        }
        bool getBT(void) const{
                return(this->bt);
        }

        qint32 getDR7(void) const{
                return(this->dr7);
        }

        quint64 getTickCounter(void) const{
                return(this->m_tickCounter);
        }

        /*-----------------MUTATORS------------------*/
        /*test success 28.10.2011*/
        void setAL(qint8 v){
                this->al = v;
                this->ax = (ax & 0xFF00) | v;
                this->eax = (eax & 0xFFFFFF00) | v;
        }
        /*test success 28.10.2011*/
        void setAH(qint8 v){
                this->ah = v;
                this->ax = (ax & 0x00FF) | (v << 8);
                this->eax = (eax & 0xFFFF00FF) | (v << 8);
        }
        /*test success 28.10.2011*/
        void setAX(qint16 v){
                this->ax = v;
                this->al = 0x00FF & v;
                this->ah = v >> 8;
                this->eax = (eax & 0xFFFF0000) | v;
        }
        /*test success 28.10.2011*/
        void setEAX(qint32 v){
                this->eax = v;
                this->ax = 0x0000FFFF & v;
                this->al = 0x000000FF & v;
                this->ah = ax >> 8;
        }
        /*test success 29.10.2011*/
        void setBL(qint8 v){
                this->bl = v;
                this->bx = (bx & 0xFF00) | v;
                this->ebx = (ebx & 0xFFFFFF00) | v;
        }
        /*test success 29.10.2011*/
        void setBH(qint8 v){
                this->bh = v;
                this->bx = (bx & 0x00FF) | (v << 8);
                this->ebx = (ebx & 0xFFFF00FF) | (v << 8);
        }
        /*test success 29.10.2011*/
        void setBX(qint16 v){
                this->bx = v;
                this->bl = 0x00FF & v;
                this->bh = v >> 8;
                this->ebx = (ebx & 0xFFFF0000) | v;
        }
        /*test success 29.10.2011*/
        void setEBX(qint32 v){
                this->ebx = v;
                this->bx = 0x0000FFFF & v;
                this->bl = 0x000000FF & v;
                this->bh = bx >> 8;
        }

        /*test success 29.10.2011*/
        void setDL(qint8 v){
                this->dl = v;
                this->dx = (dx & 0xFF00) | v;
                this->edx = (edx & 0xFFFFFF00) | v;
        }
        /*test success 29.10.2011*/
        void setDH(qint8 v){
                this->dh = v;
                this->dx = (dx & 0x00FF) | (v << 8);
                this->edx = (edx & 0xFFFF00FF) | (v << 8);
        }
        /*test success 29.10.2011*/
        void setDX(qint16 v){
                this->dx = v;
                this->dl = 0x00FF & v;
                this->dh = v >> 8;
                this->edx = (edx & 0xFFFF0000) | v;
        }
        /*test success 29.10.2011*/
        void setEDX(qint32 v){
                this->edx = v;
                this->dx = 0x0000FFFF & v;
                this->dl = 0x000000FF & v;
                this->dh = dx >> 8;
        }

        /*test success 29.10.2011*/
        void setCL(qint8 v){
                this->cl = v;
                this->cx = (cx & 0xFF00) | v;
                this->ecx = (ecx & 0xFFFFFF00) | v;
        }
        /*test success 29.10.2011*/
        void setCH(qint8 v){
                this->ch = v;
                this->cx = (cx & 0x00FF) | (v << 8);
                this->ecx = (ecx & 0xFFFF00FF) | (v << 8);
        }
        /*test success 29.10.2011*/
        void setCX(qint16 v){
                this->cx = v;
                this->cl = 0x00FF & v;
                this->ch = v >> 8;
                this->ecx = (ecx & 0xFFFF0000) | v;
        }
        /*test success 29.10.2011*/
        void setECX(qint32 v){
                this->ecx = v;
                this->cx = 0x0000FFFF & v;
                this->cl = 0x000000FF & v;
                this->ch = cx >> 8;
        }

        /*test success 29.10.2011*/
        void setBP(qint16 v){
                this->bp = v;
                this->ebp = (ebp & 0xFFFF0000) | v;
        }
        /*test success 29.10.2011*/
        void setEBP(qint32 v){
                this->ebp = v;
                this->bp = 0x0000FFFF & v;
        }

        /*test success 29.10.2011*/
        void setSI(qint16 v){
                this->si = v;
                this->esi = (esi & 0xFFFF0000) | v;
        }
        /*test success 29.10.2011*/
        void setESI(qint32 v){
                this->esi = v;
                this->si = 0x0000FFFF & v;
        }

        /*test success 29.10.2011*/
        void setDI(qint16 v){
                this->di = v;
                this->edi = (edi & 0xFFFF0000) | v;
        }
        /*test success 29.10.2011*/
        void setEDI(qint32 v){
                this->edi = v;
                this->di = 0x0000FFFF & v;
        }

        /*test success 29.10.2011*/
        void setSP(qint16 v){
                this->sp = v;
                this->esp = (esp & 0xFFFF0000) | v;
        }
        /*test success 29.10.2011*/
        void setESP(qint32 v){
                this->esp = v;
                this->sp = 0x0000FFFF & v;
        }

        void setCS(qint16 v){
                this->cs = v;
        }
        void setDS(qint16 v){
                this->ds = v;
        }
        void setSS(qint16 v){
                this->ss = v;
        }
        void setES(qint16 v){
                this->es = v;
        }
        void setFS(qint16 v){
                this->fs = v;
        }
        void setGS(qint16 v){
                this->gs = v;
        }

        void setCF(bool v){
                this->cf = v;
        }
        void setPF(bool v){
                this->pf = v;
        }
        void setAF(bool v){
                this->af = v;
        }
        void setZF(bool v){
                this->zf = v;
        }
        void setSF(bool v){
                this->sf = v;
        }
        void setOF(bool v){
                this->of = v;
        }
        void setIOPL(bool v){
                this->iopl = v;
        }
        void setNT(bool v){
                this->nt = v;
        }
        void setDF(bool v){
                this->df = v;
        }
        void setTF(bool v){
                this->tf = v;
        }
        void setIF(bool v){
                this->_if = v;
        }
        void setRF(bool v){
                this->rf = v;
        }
        void setVM(bool v){
                this->vm = v;
        }
        void setAC(bool v){
                this->ac = v;
        }

        /*test success 29.10.2011*/
        void setIP(qint16 v){
                this->ip = v;
                this->eip = (eip & 0xFFFF0000) | v;
        }
        /*test success 29.10.2011*/
        void setEIP(qint32 v){
                this->eip = v;
                this->ip = 0x0000FFFF & v;
        }

        void setPE(bool v){
                this->pe = v;
        }
        //void setMP(bool v);    DON'T TOUCH THIS COMMENTED PROTOTYPE!
        void setTS(bool v){
                this->ts = v;
        }
        void setAM(bool v){
                this->am = v;
        }
        void setCD(bool v){
                this->cd = v;
        }
        void setPG(bool v){
                this->pg = v;
        }

        void setCR2(qint32 v){
                this->cr2 = v;
        }
        void setCR3(qint32 v){
                this->cr3 = v;
        }

        void setGDTR(qint64 v){
                this->gdtr = v;
        }
        void setIDTR(qint64 v){
                this->idtr = v;
        }
        void setLDTR(qint16 v){
                this->ldtr = v;
        }
        void setTR(qint16 v){
                this->_tr = v;
        }

        void setDR0(qint32 v){
                this->dr0 = v;
        }
        void setDR1(qint32 v){
                this->dr1 = v;
        }
        void setDR2(qint32 v){
                this->dr2 = v;
        }
        void setDR3(qint32 v){
                this->dr3 = v;
        }

        void setB0(bool v){
                this->b0 = v;
        }
        void setB1(bool v){
                this->b1 = v;
        }
        void setB2(bool v){
                this->b2 = v;
        }
        void setB3(bool v){
                this->b3 = v;
        }
        void setBD(bool v){
                this->bd = v;
        }
        void setBS(bool v){
                this->bs = v;
        }
        void setBT(bool v){
                this->bt = v;
        }

        void setDR7(qint32 v){
                this->dr7 = v;
        }

        void setTickCounter(quint8 ticks){
                this->m_tickCounter = ticks;
        }

/*--------------------GENERAL METHODS---------------------------*/

        /*add 8-bit value to tick counter*/
        void addTicks(quint8 ticks){
                this->m_tickCounter += ticks;
        }

        /*increment tick counter*/
        void incTick(void){
                this->m_tickCounter++;
        }

        /*set null value to tick counter*/
        void resetTickCounter(void){
                this->m_tickCounter = 0;
        }

/*-------------------- HELPER METHODS --------------------*/
        void buildUI(void);
        void updateRegisters(void);


signals:

public slots:

};

/*
        Muammar Gaddafi was the real Hero of his country!
        Nicolas Sarkozy and Barack Obama are fuckin' bastards!
*/

#endif // PROCESSOR_H
