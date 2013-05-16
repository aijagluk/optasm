/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "source_string.h"

GSourceString::GSourceString(QWidget *parent)
    :QWidget(parent){


}

GSourceString::GSourceString(GLabelGlobal *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = LABEL_GLOBAL;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GLabelLocal *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = LABEL_LOCAL;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GLabelUnnamed *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = LABEL_UNNAMED;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GData *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = DATA_SINGLE;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GDataDup *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = DATA_DUP;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GComment *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = COMMENT;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeMOV *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_MOV;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeXCHG *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_XCHG;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeXLAT *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_XLAT;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeLEA *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_LEA;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeLDS *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_LDS;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeLES *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_LES;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeLAHF *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_LAHF;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeSAHF *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_SAHF;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodePUSH *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_PUSH;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodePOP *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_POP;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodePUSHF *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_PUSHF;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodePOPF *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_POPF;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeIN *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_IN;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeOUT *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_OUT;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeADD *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_ADD;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeADC *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_ADC;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeSUB *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_SUB;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeSBB *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_SBB;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeCMP *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_CMP;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeMUL *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_MUL;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeIMUL *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_IMUL;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeDIV *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_DIV;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeIDIV *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_IDIV;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeINC *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_INC;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeDEC *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_DEC;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeNEG *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_NEG;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeCBW *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_CBW;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeCWD *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_CWD;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeDAA *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_DAA;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeDAS *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_DAS;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeAAA *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_AAA;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeAAS *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_AAS;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeAAM *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_AAM;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeAAD *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_AAD;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeAND *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_AND;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeOR *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_OR;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeXOR *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_XOR;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeNOT *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_NOT;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeTEST *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_TEST;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeRCL *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_RCL;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeRCR *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_RCR;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeROL *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_ROL;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeROR *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_ROR;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeSAL *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_SAL;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeSAR *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_SAR;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeSHL *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_SHL;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeSHR *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_SHR;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeBT *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_BT;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeBTC *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_BTC;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeBTR *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_BTR;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeBTS *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_BTS;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeJMP *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_JMP;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeCALL *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_CALL;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeRET *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_RET;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeJL *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_JL;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeJNGE *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_JNGE;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeJNL *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_JNL;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeJGE *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_JGE;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeJLE *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_JLE;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeJNG *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_JNG;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeJNLE *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_JNLE;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeJG *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_JG;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeJB *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_JB;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeJNAE *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_JNAE;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeJC *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_JC;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeJBE *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_JBE;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeJNA *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_JNA;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeJNB *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_JNB;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeJAE *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_JAE;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeJNC *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_JNC;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeJNBE *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_JNBE;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeJA *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_JA;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeJE *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_JE;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeJZ *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_JZ;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeJP *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_JP;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeJPE *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_JPE;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeJO *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_JO;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeJS *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_JS;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeJNE *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_JNE;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeJNZ *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_JNZ;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeJNP *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_JNP;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeJPO *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_JPO;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeJNO *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_JNO;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeJNS *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_JNS;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeJCXZ *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_JCXZ;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeLOOP *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_LOOP;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeLOOPE *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_LOOPE;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeLOOPZ *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_LOOPZ;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeLOOPNE *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_LOOPNE;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeLOOPNZ *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_LOOPNZ;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeINT *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_INT;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeINTO *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_INTO;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeCLC *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_CLC;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeSTC *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_STC;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeCMC *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_CMC;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeCLD *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_CLD;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeSTD *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_STD;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeCLI *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_CLI;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeSTI *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_STI;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeHLT *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_HLT;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeWAIT *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_WAIT;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeLOCK *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_LOCK;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeESC *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_ESC;
    setNumberOfLine(nStr);
}

GSourceString::GSourceString(GOpcodeNOP *pwgt, int nStr, QWidget *parent)
    :QWidget(parent){

    this->m_pwgtBase = pwgt;
    m_SSType = OPCODE_NOP;
    setNumberOfLine(nStr);
}

//GSourceString::GSourceString(GOpcodeREP_MOVS *pwgt, int nStr, QWidget *parent)
//    :QWidget(parent){

//    this->m_pwgtBase = pwgt;
//    m_SSType = OPCODE_REP_MOVS;
//    setNumberOfLine(nStr);
//}

//GSourceString::GSourceString(GOpcodeREP_STOS *pwgt, int nStr, QWidget *parent)
//    :QWidget(parent){

//    this->m_pwgtBase = pwgt;
//    m_SSType = OPCODE_REP_STOS;
//    setNumberOfLine(nStr);
//}

//GSourceString::GSourceString(GOpcodeREPE_CMPS *pwgt, int nStr, QWidget *parent)
//    :QWidget(parent){

//    this->m_pwgtBase = pwgt;
//    m_SSType = OPCODE_REPE_CMPS;
//    setNumberOfLine(nStr);
//}

//GSourceString::GSourceString(GOpcodeREPE_SCAS *pwgt, int nStr, QWidget *parent)
//    :QWidget(parent){

//    this->m_pwgtBase = pwgt;
//    m_SSType = OPCODE_REPE_SCAS;
//    setNumberOfLine(nStr);
//}

//GSourceString::GSourceString(GOpcodeREPZ_CMPS *pwgt, int nStr, QWidget *parent)
//    :QWidget(parent){

//    this->m_pwgtBase = pwgt;
//    m_SSType = OPCODE_REPZ_CMPS;
//    setNumberOfLine(nStr);
//}

//GSourceString::GSourceString(GOpcodeREPZ_SCAS *pwgt, int nStr, QWidget *parent)
//    :QWidget(parent){

//    this->m_pwgtBase = pwgt;
//    m_SSType = OPCODE_REPZ_SCAS;
//    setNumberOfLine(nStr);
//}

//GSourceString::GSourceString(GOpcodeREPNE_MOVS *pwgt, int nStr, QWidget *parent)
//    :QWidget(parent){

//    this->m_pwgtBase = pwgt;
//    m_SSType = OPCODE_REPNE_MOVS;
//    setNumberOfLine(nStr);
//}

//GSourceString::GSourceString(GOpcodeREPNE_STOS *pwgt, int nStr, QWidget *parent)
//    :QWidget(parent){

//    this->m_pwgtBase = pwgt;
//    m_SSType = OPCODE_REPNE_STOS;
//    setNumberOfLine(nStr);
//}

//GSourceString::GSourceString(GOpcodeREPNZ_CMPS *pwgt, int nStr, QWidget *parent)
//    :QWidget(parent){

//    this->m_pwgtBase = pwgt;
//    m_SSType = OPCODE_REPNZ_CMPS;
//    setNumberOfLine(nStr);
//}

//GSourceString::GSourceString(GOpcodeREPNZ_SCAS *pwgt, int nStr, QWidget *parent)
//    :QWidget(parent){

//    this->m_pwgtBase = pwgt;
//    m_SSType = OPCODE_REPNZ_SCAS;
//    setNumberOfLine(nStr);
//}
