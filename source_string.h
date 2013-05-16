/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/


#ifndef SOURCE_STRING_H
#define SOURCE_STRING_H

#include <QWidget>
#include "data.h"
#include "data_dup.h"
#include "directive.h"
#include "comment.h"
#include "services_types.h"
#include "label_global.h"
#include "label_local.h"
#include "label_unnamed.h"
#include "opcode_mov.h"
#include "opcode_xchg.h"
#include "opcode_xlat.h"
#include "opcode_lea.h"
#include "opcode_lds.h"
#include "opcode_les.h"
#include "opcode_lahf.h"
#include "opcode_sahf.h"
#include "opcode_push.h"
#include "opcode_pop.h"
#include "opcode_pushf.h"
#include "opcode_popf.h"
#include "opcode_in.h"
#include "opcode_out.h"
#include "opcode_add.h"
#include "opcode_adc.h"
#include "opcode_sub.h"
#include "opcode_sbb.h"
#include "opcode_cmp.h"
#include "opcode_mul.h"
#include "opcode_imul.h"
#include "opcode_div.h"
#include "opcode_idiv.h"
#include "opcode_inc.h"
#include "opcode_dec.h"
#include "opcode_neg.h"
#include "opcode_cbw.h"
#include "opcode_cwd.h"
#include "opcode_daa.h"
#include "opcode_das.h"
#include "opcode_aaa.h"
#include "opcode_aas.h"
#include "opcode_aam.h"
#include "opcode_aad.h"
#include "opcode_and.h"
#include "opcode_or.h"
#include "opcode_xor.h"
#include "opcode_not.h"
#include "opcode_test.h"
#include "opcode_rcl.h"
#include "opcode_rcr.h"
#include "opcode_rol.h"
#include "opcode_ror.h"
#include "opcode_sal.h"
#include "opcode_sar.h"
#include "opcode_shl.h"
#include "opcode_shr.h"
#include "opcode_bt.h"
#include "opcode_btc.h"
#include "opcode_btr.h"
#include "opcode_bts.h"
#include "opcode_jmp.h"
#include "opcode_call.h"
#include "opcode_ret.h"
#include "opcode_jl.h"
#include "opcode_jnge.h"
#include "opcode_jnl.h"
#include "opcode_jge.h"
#include "opcode_jle.h"
#include "opcode_jng.h"
#include "opcode_jnle.h"
#include "opcode_jg.h"
#include "opcode_jb.h"
#include "opcode_jnae.h"
#include "opcode_jc.h"
#include "opcode_jbe.h"
#include "opcode_jna.h"
#include "opcode_jnb.h"
#include "opcode_jae.h"
#include "opcode_jnc.h"
#include "opcode_jnbe.h"
#include "opcode_ja.h"
#include "opcode_je.h"
#include "opcode_jz.h"
#include "opcode_jp.h"
#include "opcode_jpe.h"
#include "opcode_jo.h"
#include "opcode_js.h"
#include "opcode_jne.h"
#include "opcode_jnz.h"
#include "opcode_jnp.h"
#include "opcode_jpo.h"
#include "opcode_jno.h"
#include "opcode_jns.h"
#include "opcode_jcxz.h"
#include "opcode_loop.h"
#include "opcode_loope.h"
#include "opcode_loopz.h"
#include "opcode_loopne.h"
#include "opcode_loopnz.h"
#include "opcode_int.h"
#include "opcode_into.h"
#include "opcode_clc.h"
#include "opcode_stc.h"
#include "opcode_cmc.h"
#include "opcode_cld.h"
#include "opcode_std.h"
#include "opcode_cli.h"
#include "opcode_sti.h"
#include "opcode_hlt.h"
#include "opcode_wait.h"
#include "opcode_lock.h"
#include "opcode_esc.h"
#include "opcode_nop.h"
#include "opcode_rep_movs.h"
#include "opcode_rep_stos.h"
#include "opcode_repe_cmps.h"
#include "opcode_repe_scas.h"
#include "opcode_repz_cmps.h"
#include "opcode_repz_scas.h"
#include "opcode_repne_movs.h"
#include "opcode_repne_stos.h"
#include "opcode_repnz_cmps.h"
#include "opcode_repnz_scas.h"


class GSourceString : public QWidget{
    Q_OBJECT
public:
    explicit GSourceString(QWidget *parent = 0);
    GSourceString(GLabelGlobal* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GLabelLocal* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GLabelUnnamed* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GData* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GDataDup* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GComment* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeMOV* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeXCHG* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeXLAT* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeLEA* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeLDS* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeLES* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeLAHF* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeSAHF* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodePUSH* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodePOP* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodePUSHF* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodePOPF* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeIN* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeOUT* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeADD* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeADC* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeSUB* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeSBB* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeCMP* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeMUL* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeIMUL* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeDIV* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeIDIV* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeINC* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeDEC* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeNEG* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeCBW* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeCWD* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeDAA* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeDAS* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeAAA* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeAAS* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeAAM* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeAAD* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeAND* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeOR* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeXOR* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeNOT* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeTEST* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeRCL* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeRCR* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeROL* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeROR* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeSAL* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeSAR* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeSHL* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeSHR* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeBT* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeBTC* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeBTR* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeBTS* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeJMP* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeCALL* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeRET* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeJL* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeJNGE* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeJNL* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeJGE* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeJLE* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeJNG* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeJNLE* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeJG* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeJB* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeJNAE* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeJC* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeJBE* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeJNA* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeJNB* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeJAE* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeJNC* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeJNBE* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeJA* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeJE* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeJZ* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeJP* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeJPE* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeJO* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeJS* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeJNE* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeJNZ* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeJNP* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeJPO* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeJNO* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeJNS* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeJCXZ* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeLOOP* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeLOOPE* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeLOOPZ* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeLOOPNE* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeLOOPNZ* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeINT* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeINTO* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeCLC* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeSTC* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeCMC* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeCLD* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeSTD* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeCLI* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeSTI* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeHLT* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeWAIT* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeLOCK* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeESC* pwgt, int nStr, QWidget* parent = 0);
    GSourceString(GOpcodeNOP* pwgt, int nStr, QWidget* parent = 0);
//    GSourceString(GOpcodeREP_MOVS* pwgt, int nStr, QWidget* parent = 0);
//    GSourceString(GOpcodeREP_STOS* pwgt, int nStr, QWidget* parent = 0);
//    GSourceString(GOpcodeREPE_CMPS* pwgt, int nStr, QWidget* parent = 0);
//    GSourceString(GOpcodeREPE_SCAS* pwgt, int nStr, QWidget* parent = 0);
//    GSourceString(GOpcodeREPZ_CMPS* pwgt, int nStr, QWidget* parent = 0);
//    GSourceString(GOpcodeREPZ_SCAS* pwgt, int nStr, QWidget* parent = 0);
//    GSourceString(GOpcodeREPNE_MOVS* pwgt, int nStr, QWidget* parent = 0);
//    GSourceString(GOpcodeREPNE_STOS* pwgt, int nStr, QWidget* parent = 0);
//    GSourceString(GOpcodeREPNZ_CMPS* pwgt, int nStr, QWidget* parent = 0);
//    GSourceString(GOpcodeREPNZ_SCAS* pwgt, int nStr, QWidget* parent = 0);


    int numberOfLine(void) const{
        return(this->m_nNumberOfLine);
    }

    void setNumberOfLine(int n){
        if(0 < n && n < 10000){
            this->m_nNumberOfLine = n;
        }
        //to add error message!
    }

    QWidget* sourceStringBase(void){
        return(m_pwgtBase);
    }

    SourceStringType m_SSType;

private:
    int m_nNumberOfLine;
    QWidget* m_pwgtBase;

signals:
    
public slots:
    
};

#endif // SOURCE_STRING_H
