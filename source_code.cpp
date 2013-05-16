/**********************************************************************
*    optAsm v1.0                                                      *
*    Developer:   Max I. Belyaev        (uncleglitch@gmail.com)       *
*    Idea:        Andrey S. Miroshnikov (mirandrey@mail.ru)           *
*    Copyright by Andrey S. Miroshnikov and Max I. Belyaev, 2011-2013 *
**********************************************************************/

#include "source_code.h"
#include "services_types.h"

GSourceCode::GSourceCode(QWidget *parent)
    :QWidget(parent){

    m_pstrsSrc = new QVector<GSourceString*>();
}

void GSourceCode::addString(GSourceString *pstr){
    m_pstrsSrc->push_back(pstr);
}

void GSourceCode::removeString(int index){
    m_pstrsSrc->remove(index);
}



int GSourceCode::getTicks(int index){

    SourceStringType SSType = m_pstrsSrc->at(index)->m_SSType;
    int nCurrentTicks;

    switch(SSType){
    case LABEL_GLOBAL:
        nCurrentTicks = 0;
        break;
    case LABEL_LOCAL:
        nCurrentTicks = 0;
        break;
    case LABEL_UNNAMED:
        nCurrentTicks = 0;
        break;
    case DATA_SINGLE:
        nCurrentTicks = 0;
        break;
    case DATA_DUP:
        nCurrentTicks = 0;
        break;
    case COMMENT:
        nCurrentTicks = 0;
        break;
    case OPCODE_MOV:
        nCurrentTicks = ((GOpcodeMOV*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_XCHG:
        nCurrentTicks = ((GOpcodeXCHG*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_XLAT:
        nCurrentTicks = ((GOpcodeXLAT*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_LEA:
        nCurrentTicks = ((GOpcodeLEA*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_LDS:
        nCurrentTicks = ((GOpcodeLDS*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_LES:
        nCurrentTicks = ((GOpcodeLES*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_LAHF:
        nCurrentTicks = ((GOpcodeLAHF*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_SAHF:
        nCurrentTicks = ((GOpcodeSAHF*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_PUSH:
        nCurrentTicks = ((GOpcodePUSH*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_POP:
        nCurrentTicks = ((GOpcodePOP*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_PUSHF:
        nCurrentTicks = ((GOpcodePUSHF*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_POPF:
        nCurrentTicks = ((GOpcodePOPF*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_IN:
        nCurrentTicks = ((GOpcodeIN*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_OUT:
        nCurrentTicks = ((GOpcodeOUT*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_ADD:
        nCurrentTicks = ((GOpcodeADD*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_ADC:
        nCurrentTicks = ((GOpcodeADC*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_SUB:
        nCurrentTicks = ((GOpcodeSUB*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_SBB:
        nCurrentTicks = ((GOpcodeSBB*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_CMP:
        nCurrentTicks = ((GOpcodeCMP*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_MUL:
        nCurrentTicks = ((GOpcodeMUL*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_IMUL:
        nCurrentTicks = ((GOpcodeIMUL*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_DIV:
        nCurrentTicks = ((GOpcodeDIV*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_IDIV:
        nCurrentTicks = ((GOpcodeIDIV*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_INC:
        nCurrentTicks = ((GOpcodeINC*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_DEC:
        nCurrentTicks = ((GOpcodeDEC*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_NEG:
        nCurrentTicks = ((GOpcodeNEG*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_CBW:
        nCurrentTicks = ((GOpcodeCBW*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_CWD:
        nCurrentTicks = ((GOpcodeCWD*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_DAA:
        nCurrentTicks = ((GOpcodeDAA*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_DAS:
        nCurrentTicks = ((GOpcodeDAS*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_AAA:
        nCurrentTicks = ((GOpcodeAAA*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_AAS:
        nCurrentTicks = ((GOpcodeAAS*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_AAM:
        nCurrentTicks = ((GOpcodeAAM*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_AAD:
        nCurrentTicks = ((GOpcodeAAD*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_AND:
        nCurrentTicks = ((GOpcodeAND*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_OR:
        nCurrentTicks = ((GOpcodeOR*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_XOR:
        nCurrentTicks = ((GOpcodeXOR*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_NOT:
        nCurrentTicks = ((GOpcodeNOT*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_TEST:
        nCurrentTicks = ((GOpcodeTEST*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_RCL:
        nCurrentTicks = ((GOpcodeRCL*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_RCR:
        nCurrentTicks = ((GOpcodeRCR*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_ROL:
        nCurrentTicks = ((GOpcodeROL*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_ROR:
        nCurrentTicks = ((GOpcodeROR*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_SAL:
        nCurrentTicks = ((GOpcodeSAL*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_SAR:
        nCurrentTicks = ((GOpcodeSAR*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_SHL:
        nCurrentTicks = ((GOpcodeSHL*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_SHR:
        nCurrentTicks = ((GOpcodeSHR*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_BT:
        nCurrentTicks = ((GOpcodeBT*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_BTC:
        nCurrentTicks = ((GOpcodeBTC*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_BTR:
        nCurrentTicks = ((GOpcodeBTR*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_BTS:
        nCurrentTicks = ((GOpcodeBTS*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_JMP:
        nCurrentTicks = ((GOpcodeJMP*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_CALL:
        nCurrentTicks = ((GOpcodeCALL*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_RET:
        nCurrentTicks = ((GOpcodeRET*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_JL:
        nCurrentTicks = ((GOpcodeJL*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_JNGE:
        nCurrentTicks = ((GOpcodeJNGE*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_JNL:
        nCurrentTicks = ((GOpcodeJNL*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_JGE:
        nCurrentTicks = ((GOpcodeJGE*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_JLE:
        nCurrentTicks = ((GOpcodeJLE*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_JNG:
        nCurrentTicks = ((GOpcodeJNG*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_JNLE:
        nCurrentTicks = ((GOpcodeJNLE*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_JG:
        nCurrentTicks = ((GOpcodeJG*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_JB:
        nCurrentTicks = ((GOpcodeJB*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_JNAE:
        nCurrentTicks = ((GOpcodeJNAE*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_JC:
        nCurrentTicks = ((GOpcodeJC*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_JBE:
        nCurrentTicks = ((GOpcodeJBE*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_JNA:
        nCurrentTicks = ((GOpcodeJNA*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_JNB:
        nCurrentTicks = ((GOpcodeJNB*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_JAE:
        nCurrentTicks = ((GOpcodeJAE*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_JNC:
        nCurrentTicks = ((GOpcodeJNC*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_JNBE:
        nCurrentTicks = ((GOpcodeJNBE*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_JA:
        nCurrentTicks = ((GOpcodeJA*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_JE:
        nCurrentTicks = ((GOpcodeJE*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_JZ:
        nCurrentTicks = ((GOpcodeJZ*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_JP:
        nCurrentTicks = ((GOpcodeJP*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_JPE:
        nCurrentTicks = ((GOpcodeJPE*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_JO:
        nCurrentTicks = ((GOpcodeJO*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_JS:
        nCurrentTicks = ((GOpcodeJS*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_JNE:
        nCurrentTicks = ((GOpcodeJNE*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_JNZ:
        nCurrentTicks = ((GOpcodeJNZ*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_JNP:
        nCurrentTicks = ((GOpcodeJNP*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_JPO:
        nCurrentTicks = ((GOpcodeJPO*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_JNO:
        nCurrentTicks = ((GOpcodeJNO*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_JNS:
        nCurrentTicks = ((GOpcodeJNS*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_JCXZ:
        nCurrentTicks = ((GOpcodeJCXZ*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_LOOP:
        nCurrentTicks = ((GOpcodeLOOP*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_LOOPE:
        nCurrentTicks = ((GOpcodeLOOPE*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_LOOPZ:
        nCurrentTicks = ((GOpcodeLOOPZ*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_LOOPNE:
        nCurrentTicks = ((GOpcodeLOOPNE*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_LOOPNZ:
        nCurrentTicks = ((GOpcodeLOOPNZ*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_INT:
        nCurrentTicks = ((GOpcodeINT*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_INTO:
        nCurrentTicks = ((GOpcodeINTO*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_CLC:
        nCurrentTicks = ((GOpcodeCLC*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_STC:
        nCurrentTicks = ((GOpcodeSTC*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_CMC:
        nCurrentTicks = ((GOpcodeCMC*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_CLD:
        nCurrentTicks = ((GOpcodeCLD*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_STD:
        nCurrentTicks = ((GOpcodeSTD*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_CLI:
        nCurrentTicks = ((GOpcodeCLI*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_STI:
        nCurrentTicks = ((GOpcodeSTI*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_HLT:
        nCurrentTicks = ((GOpcodeHLT*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_WAIT:
        nCurrentTicks = ((GOpcodeWAIT*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_LOCK:
        nCurrentTicks = ((GOpcodeLOCK*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_ESC:
        nCurrentTicks = ((GOpcodeESC*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
    case OPCODE_NOP:
        nCurrentTicks = ((GOpcodeNOP*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
        break;
//    case OPCODE_REP_MOVS:
//        nCurrentTicks = ((GOpcodeREP_MOVS*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
//        break;
//    case OPCODE_REP_STOS:
//        nCurrentTicks = ((GOpcodeREP_STOS*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
//        break;
//    case OPCODE_REPE_CMPS:
//        nCurrentTicks = ((GOpcodeREPE_CMPS*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
//        break;
//    case OPCODE_REPE_SCAS:
//        nCurrentTicks = ((GOpcodeREPE_SCAS*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
//        break;
//    case OPCODE_REPZ_CMPS:
//        nCurrentTicks = ((GOpcodeREPZ_CMPS*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
//        break;
//    case OPCODE_REPZ_SCAS:
//        nCurrentTicks = ((GOpcodeREPZ_SCAS*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
//        break;
//    case OPCODE_REPNE_MOVS:
//        nCurrentTicks = ((GOpcodeREPNE_MOVS*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
//        break;
//    case OPCODE_REPNE_STOS:
//        nCurrentTicks = ((GOpcodeREPNE_STOS*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
//        break;
//    case OPCODE_REPNZ_CMPS:
//        nCurrentTicks = ((GOpcodeREPNZ_CMPS*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
//        break;
//    case OPCODE_REPNZ_SCAS:
//        nCurrentTicks = ((GOpcodeREPNZ_SCAS*)m_pstrsSrc->at(index)->sourceStringBase())->ticks();
//        break;
    }

    return(nCurrentTicks);
}

int GSourceCode::getBytes(int index){
    SourceStringType SSType = m_pstrsSrc->at(index)->m_SSType;
    int nCurrentBytes;

    switch(SSType){
    case LABEL_GLOBAL:
        nCurrentBytes = 0;
        break;
    case LABEL_LOCAL:
        nCurrentBytes = 0;
        break;
    case LABEL_UNNAMED:
        nCurrentBytes = 0;
        break;
    case DATA_SINGLE:
        nCurrentBytes = 0;
        break;
    case DATA_DUP:
        nCurrentBytes = 0;
        break;
    case COMMENT:
        nCurrentBytes = 0;
        break;
    case OPCODE_MOV:
        nCurrentBytes = ((GOpcodeMOV*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_XCHG:
        nCurrentBytes = ((GOpcodeXCHG*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_XLAT:
        nCurrentBytes = ((GOpcodeXLAT*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_LEA:
        nCurrentBytes = ((GOpcodeLEA*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_LDS:
        nCurrentBytes = ((GOpcodeLDS*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_LES:
        nCurrentBytes = ((GOpcodeLES*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_LAHF:
        nCurrentBytes = ((GOpcodeLAHF*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_SAHF:
        nCurrentBytes = ((GOpcodeSAHF*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_PUSH:
        nCurrentBytes = ((GOpcodePUSH*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_POP:
        nCurrentBytes = ((GOpcodePOP*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_PUSHF:
        nCurrentBytes = ((GOpcodePUSHF*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_POPF:
        nCurrentBytes = ((GOpcodePOPF*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_IN:
        nCurrentBytes = ((GOpcodeIN*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_OUT:
        nCurrentBytes = ((GOpcodeOUT*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_ADD:
        nCurrentBytes = ((GOpcodeADD*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_ADC:
        nCurrentBytes = ((GOpcodeADC*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_SUB:
        nCurrentBytes = ((GOpcodeSUB*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_SBB:
        nCurrentBytes = ((GOpcodeSBB*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_CMP:
        nCurrentBytes = ((GOpcodeCMP*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_MUL:
        nCurrentBytes = ((GOpcodeMUL*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_IMUL:
        nCurrentBytes = ((GOpcodeIMUL*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_DIV:
        nCurrentBytes = ((GOpcodeDIV*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_IDIV:
        nCurrentBytes = ((GOpcodeIDIV*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_INC:
        nCurrentBytes = ((GOpcodeINC*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_DEC:
        nCurrentBytes = ((GOpcodeDEC*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_NEG:
        nCurrentBytes = ((GOpcodeNEG*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_CBW:
        nCurrentBytes = ((GOpcodeCBW*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_CWD:
        nCurrentBytes = ((GOpcodeCWD*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_DAA:
        nCurrentBytes = ((GOpcodeDAA*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_DAS:
        nCurrentBytes = ((GOpcodeDAS*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_AAA:
        nCurrentBytes = ((GOpcodeAAA*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_AAS:
        nCurrentBytes = ((GOpcodeAAS*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_AAM:
        nCurrentBytes = ((GOpcodeAAM*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_AAD:
        nCurrentBytes = ((GOpcodeAAD*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_AND:
        nCurrentBytes = ((GOpcodeAND*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_OR:
        nCurrentBytes = ((GOpcodeOR*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_XOR:
        nCurrentBytes = ((GOpcodeXOR*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_NOT:
        nCurrentBytes = ((GOpcodeNOT*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_TEST:
        nCurrentBytes = ((GOpcodeTEST*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_RCL:
        nCurrentBytes = ((GOpcodeRCL*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_RCR:
        nCurrentBytes = ((GOpcodeRCR*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_ROL:
        nCurrentBytes = ((GOpcodeROL*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_ROR:
        nCurrentBytes = ((GOpcodeROR*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_SAL:
        nCurrentBytes = ((GOpcodeSAL*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_SAR:
        nCurrentBytes = ((GOpcodeSAR*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_SHL:
        nCurrentBytes = ((GOpcodeSHL*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_SHR:
        nCurrentBytes = ((GOpcodeSHR*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_BT:
        nCurrentBytes = ((GOpcodeBT*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_BTC:
        nCurrentBytes = ((GOpcodeBTC*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_BTR:
        nCurrentBytes = ((GOpcodeBTR*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_BTS:
        nCurrentBytes = ((GOpcodeBTS*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_JMP:
        nCurrentBytes = ((GOpcodeJMP*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_CALL:
        nCurrentBytes = ((GOpcodeCALL*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_RET:
        nCurrentBytes = ((GOpcodeRET*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_JL:
        nCurrentBytes = ((GOpcodeJL*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_JNGE:
        nCurrentBytes = ((GOpcodeJNGE*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_JNL:
        nCurrentBytes = ((GOpcodeJNL*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_JGE:
        nCurrentBytes = ((GOpcodeJGE*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_JLE:
        nCurrentBytes = ((GOpcodeJLE*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_JNG:
        nCurrentBytes = ((GOpcodeJNG*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_JNLE:
        nCurrentBytes = ((GOpcodeJNLE*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_JG:
        nCurrentBytes = ((GOpcodeJG*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_JB:
        nCurrentBytes = ((GOpcodeJB*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_JNAE:
        nCurrentBytes = ((GOpcodeJNAE*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_JC:
        nCurrentBytes = ((GOpcodeJC*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_JBE:
        nCurrentBytes = ((GOpcodeJBE*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_JNA:
        nCurrentBytes = ((GOpcodeJNA*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_JNB:
        nCurrentBytes = ((GOpcodeJNB*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_JAE:
        nCurrentBytes = ((GOpcodeJAE*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_JNC:
        nCurrentBytes = ((GOpcodeJNC*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_JNBE:
        nCurrentBytes = ((GOpcodeJNBE*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_JA:
        nCurrentBytes = ((GOpcodeJA*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_JE:
        nCurrentBytes = ((GOpcodeJE*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_JZ:
        nCurrentBytes = ((GOpcodeJZ*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_JP:
        nCurrentBytes = ((GOpcodeJP*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_JPE:
        nCurrentBytes = ((GOpcodeJPE*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_JO:
        nCurrentBytes = ((GOpcodeJO*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_JS:
        nCurrentBytes = ((GOpcodeJS*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_JNE:
        nCurrentBytes = ((GOpcodeJNE*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_JNZ:
        nCurrentBytes = ((GOpcodeJNZ*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_JNP:
        nCurrentBytes = ((GOpcodeJNP*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_JPO:
        nCurrentBytes = ((GOpcodeJPO*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_JNO:
        nCurrentBytes = ((GOpcodeJNO*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_JNS:
        nCurrentBytes = ((GOpcodeJNS*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_JCXZ:
        nCurrentBytes = ((GOpcodeJCXZ*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_LOOP:
        nCurrentBytes = ((GOpcodeLOOP*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_LOOPE:
        nCurrentBytes = ((GOpcodeLOOPE*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_LOOPZ:
        nCurrentBytes = ((GOpcodeLOOPZ*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_LOOPNE:
        nCurrentBytes = ((GOpcodeLOOPNE*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_LOOPNZ:
        nCurrentBytes = ((GOpcodeLOOPNZ*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_INT:
        nCurrentBytes = ((GOpcodeINT*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_INTO:
        nCurrentBytes = ((GOpcodeINTO*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_CLC:
        nCurrentBytes = ((GOpcodeCLC*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_STC:
        nCurrentBytes = ((GOpcodeSTC*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_CMC:
        nCurrentBytes = ((GOpcodeCMC*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_CLD:
        nCurrentBytes = ((GOpcodeCLD*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_STD:
        nCurrentBytes = ((GOpcodeSTD*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_CLI:
        nCurrentBytes = ((GOpcodeCLI*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_STI:
        nCurrentBytes = ((GOpcodeSTI*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_HLT:
        nCurrentBytes = ((GOpcodeHLT*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_WAIT:
        nCurrentBytes = ((GOpcodeWAIT*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_LOCK:
        nCurrentBytes = ((GOpcodeLOCK*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_ESC:
        nCurrentBytes = ((GOpcodeESC*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
    case OPCODE_NOP:
        nCurrentBytes = ((GOpcodeNOP*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
        break;
//    case OPCODE_REP_MOVS:
//        nCurrentBytes = ((GOpcodeREP_MOVS*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
//        break;
//    case OPCODE_REP_STOS:
//        nCurrentBytes = ((GOpcodeREP_STOS*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
//        break;
//    case OPCODE_REPE_CMPS:
//        nCurrentBytes = ((GOpcodeREPE_CMPS*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
//        break;
//    case OPCODE_REPE_SCAS:
//        nCurrentBytes = ((GOpcodeREPE_SCAS*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
//        break;
//    case OPCODE_REPZ_CMPS:
//        nCurrentBytes = ((GOpcodeREPZ_CMPS*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
//        break;
//    case OPCODE_REPZ_SCAS:
//        nCurrentBytes = ((GOpcodeREPZ_SCAS*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
//        break;
//    case OPCODE_REPNE_MOVS:
//        nCurrentBytes = ((GOpcodeREPNE_MOVS*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
//        break;
//    case OPCODE_REPNE_STOS:
//        nCurrentBytes = ((GOpcodeREPNE_STOS*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
//        break;
//    case OPCODE_REPNZ_CMPS:
//        nCurrentBytes = ((GOpcodeREPNZ_CMPS*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
//        break;
//    case OPCODE_REPNZ_SCAS:
//        nCurrentBytes = ((GOpcodeREPNZ_SCAS*)m_pstrsSrc->at(index)->sourceStringBase())->bytes();
//        break;
    }

    return(nCurrentBytes);
}

QStringList *GSourceCode::getStringList(void){
    QStringList* strlstSources = new QStringList();
    QString tmp;
    SourceStringType SSType;
    int nLine;

    QVector<GSourceString*>::iterator it;// = m_pstrsSrc->begin();
    for(it = m_pstrsSrc->begin(); it != m_pstrsSrc->end(); ++it){
        SSType = (*it)->m_SSType;
        nLine = (*it)->numberOfLine();

        switch(SSType){
        case LABEL_GLOBAL:
            tmp = ((GLabelGlobal*)(*it)->sourceStringBase())->sourceCode();
            break;
        case LABEL_LOCAL:
            tmp = ((GLabelLocal*)(*it)->sourceStringBase())->sourceCode();
            break;
        case LABEL_UNNAMED:
            tmp = ((GLabelUnnamed*)(*it)->sourceStringBase())->sourceCode();
            break;
        case DATA_SINGLE:
            tmp = ((GData*)(*it)->sourceStringBase())->sourceCode();
            break;
        case DATA_DUP:
            tmp = ((GDataDup*)(*it)->sourceStringBase())->sourceCode();
            break;
        case COMMENT:
            tmp = ((GComment*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_MOV:
            tmp = ((GOpcodeMOV*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_XCHG:
            tmp = ((GOpcodeXCHG*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_XLAT:
            tmp = ((GOpcodeXLAT*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_LEA:
            tmp = ((GOpcodeLEA*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_LDS:
            tmp = ((GOpcodeLDS*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_LES:
            tmp = ((GOpcodeLES*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_LAHF:
            tmp = ((GOpcodeLAHF*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_SAHF:
            tmp = ((GOpcodeSAHF*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_PUSH:
            tmp = ((GOpcodePUSH*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_POP:
            tmp = ((GOpcodePOP*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_PUSHF:
            tmp = ((GOpcodePUSHF*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_POPF:
            tmp = ((GOpcodePOPF*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_IN:
            tmp = ((GOpcodeIN*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_OUT:
            tmp = ((GOpcodeOUT*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_ADD:
            tmp = ((GOpcodeADD*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_ADC:
            tmp = ((GOpcodeADC*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_SUB:
            tmp = ((GOpcodeSUB*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_SBB:
            tmp = ((GOpcodeSBB*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_CMP:
            tmp = ((GOpcodeCMP*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_MUL:
            tmp = ((GOpcodeMUL*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_IMUL:
            tmp = ((GOpcodeIMUL*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_DIV:
            tmp = ((GOpcodeDIV*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_IDIV:
            tmp = ((GOpcodeIDIV*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_INC:
            tmp = ((GOpcodeINC*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_DEC:
            tmp = ((GOpcodeDEC*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_NEG:
            tmp = ((GOpcodeNEG*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_CBW:
            tmp = ((GOpcodeCBW*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_CWD:
            tmp = ((GOpcodeCWD*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_DAA:
            tmp = ((GOpcodeDAA*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_DAS:
            tmp = ((GOpcodeDAS*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_AAA:
            tmp = ((GOpcodeAAA*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_AAS:
            tmp = ((GOpcodeAAS*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_AAM:
            tmp = ((GOpcodeAAM*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_AAD:
            tmp = ((GOpcodeAAD*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_AND:
            tmp = ((GOpcodeAND*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_OR:
            tmp = ((GOpcodeOR*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_XOR:
            tmp = ((GOpcodeXOR*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_NOT:
            tmp = ((GOpcodeNOT*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_TEST:
            tmp = ((GOpcodeTEST*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_RCL:
            tmp = ((GOpcodeRCL*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_RCR:
            tmp = ((GOpcodeRCR*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_ROL:
            tmp = ((GOpcodeROL*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_ROR:
            tmp = ((GOpcodeROR*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_SAL:
            tmp = ((GOpcodeSAL*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_SAR:
            tmp = ((GOpcodeSAR*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_SHL:
            tmp = ((GOpcodeSHL*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_SHR:
            tmp = ((GOpcodeSHR*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_BT:
            tmp = ((GOpcodeBT*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_BTC:
            tmp = ((GOpcodeBTC*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_BTR:
            tmp = ((GOpcodeBTR*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_BTS:
            tmp = ((GOpcodeBTS*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_JMP:
            tmp = ((GOpcodeJMP*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_CALL:
            tmp = ((GOpcodeCALL*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_RET:
            tmp = ((GOpcodeRET*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_JL:
            tmp = ((GOpcodeJL*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_JNGE:
            tmp = ((GOpcodeJNGE*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_JNL:
            tmp = ((GOpcodeJNL*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_JGE:
            tmp = ((GOpcodeJGE*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_JLE:
            tmp = ((GOpcodeJLE*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_JNG:
            tmp = ((GOpcodeJNG*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_JNLE:
            tmp = ((GOpcodeJNLE*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_JG:
            tmp = ((GOpcodeJG*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_JB:
            tmp = ((GOpcodeJB*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_JNAE:
            tmp = ((GOpcodeJNAE*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_JC:
            tmp = ((GOpcodeJC*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_JBE:
            tmp = ((GOpcodeJBE*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_JNA:
            tmp = ((GOpcodeJNA*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_JNB:
            tmp = ((GOpcodeJNB*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_JAE:
            tmp = ((GOpcodeJAE*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_JNC:
            tmp = ((GOpcodeJNC*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_JNBE:
            tmp = ((GOpcodeJNBE*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_JA:
            tmp = ((GOpcodeJA*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_JE:
            tmp = ((GOpcodeJE*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_JZ:
            tmp = ((GOpcodeJZ*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_JP:
            tmp = ((GOpcodeJP*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_JPE:
            tmp = ((GOpcodeJPE*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_JO:
            tmp = ((GOpcodeJO*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_JS:
            tmp = ((GOpcodeJS*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_JNE:
            tmp = ((GOpcodeJNE*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_JNZ:
            tmp = ((GOpcodeJNZ*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_JNP:
            tmp = ((GOpcodeJNP*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_JPO:
            tmp = ((GOpcodeJPO*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_JNO:
            tmp = ((GOpcodeJNO*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_JNS:
            tmp = ((GOpcodeJNS*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_JCXZ:
            tmp = ((GOpcodeJCXZ*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_LOOP:
            tmp = ((GOpcodeLOOP*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_LOOPE:
            tmp = ((GOpcodeLOOPE*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_LOOPZ:
            tmp = ((GOpcodeLOOPZ*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_LOOPNE:
            tmp = ((GOpcodeLOOPNE*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_LOOPNZ:
            tmp = ((GOpcodeLOOPNZ*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_INT:
            tmp = ((GOpcodeINT*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_INTO:
            tmp = ((GOpcodeINTO*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_CLC:
            tmp = ((GOpcodeCLC*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_STC:
            tmp = ((GOpcodeSTC*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_CMC:
            tmp = ((GOpcodeCMC*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_CLD:
            tmp = ((GOpcodeCLD*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_STD:
            tmp = ((GOpcodeSTD*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_CLI:
            tmp = ((GOpcodeCLI*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_STI:
            tmp = ((GOpcodeSTI*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_HLT:
            tmp = ((GOpcodeHLT*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_WAIT:
            tmp = ((GOpcodeWAIT*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_LOCK:
            tmp = ((GOpcodeLOCK*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_ESC:
            tmp = ((GOpcodeESC*)(*it)->sourceStringBase())->sourceCode();
            break;
        case OPCODE_NOP:
            tmp = ((GOpcodeNOP*)(*it)->sourceStringBase())->sourceCode();
            break;
//        case OPCODE_REP_MOVS:
//            tmp = ((GOpcodeREP_MOVS*)(*it)->sourceStringBase())->sourceCode();
//            break;
//        case OPCODE_REP_STOS:
//            tmp = ((GOpcodeREP_STOS*)(*it)->sourceStringBase())->sourceCode();
//            break;
//        case OPCODE_REPE_CMPS:
//            tmp = ((GOpcodeREPE_CMPS*)(*it)->sourceStringBase())->sourceCode();
//            break;
//        case OPCODE_REPE_SCAS:
//            tmp = ((GOpcodeREPE_SCAS*)(*it)->sourceStringBase())->sourceCode();
//            break;
//        case OPCODE_REPZ_CMPS:
//            tmp = ((GOpcodeREPZ_CMPS*)(*it)->sourceStringBase())->sourceCode();
//            break;
//        case OPCODE_REPZ_SCAS:
//            tmp = ((GOpcodeREPZ_SCAS*)(*it)->sourceStringBase())->sourceCode();
//            break;
//        case OPCODE_REPNE_MOVS:
//            tmp = ((GOpcodeREPNE_MOVS*)(*it)->sourceStringBase())->sourceCode();
//            break;
//        case OPCODE_REPNE_STOS:
//            tmp = ((GOpcodeREPNE_STOS*)(*it)->sourceStringBase())->sourceCode();
//            break;
//        case OPCODE_REPNZ_CMPS:
//            tmp = ((GOpcodeREPNZ_CMPS*)(*it)->sourceStringBase())->sourceCode();
//            break;
//        case OPCODE_REPNZ_SCAS:
//            tmp = ((GOpcodeREPNZ_SCAS*)(*it)->sourceStringBase())->sourceCode();
//            break;
        }


        if(SSType != LABEL_GLOBAL  &&
           SSType != LABEL_LOCAL   &&
           SSType != LABEL_UNNAMED &&
           SSType != COMMENT){

            tmp.push_front("\t");
        }

        strlstSources->insert(nLine - 1, tmp);
    }

    return(strlstSources);
}

int GSourceCode::getCommonTicks(void){

    return getTicksBetweenLines(1, m_pstrsSrc->count());
}

int GSourceCode::getTicksBetweenLines(int from, int to){
    int sum(0);
    SourceStringType SSType;

    fullAnalyse();

    QVector<GSourceString*>::iterator it;// = m_pstrsSrc->begin();

    for(it = m_pstrsSrc->begin(); it != m_pstrsSrc->end(); ++it){

        if ((*it)->numberOfLine() >= from && (*it)->numberOfLine() <= to) {
            SSType = (*it)->m_SSType;

            switch(SSType){
            case LABEL_GLOBAL:
                sum += 0;
                break;
            case LABEL_LOCAL:
                sum += 0;
                break;
            case LABEL_UNNAMED:
                sum += 0;
                break;
            case DATA_SINGLE:
                sum += 0;
                break;
            case DATA_DUP:
                sum += 0;
                break;
            case COMMENT:
                sum += 0;
                break;
            case OPCODE_MOV:
                sum += ((GOpcodeMOV*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_XCHG:
                sum += ((GOpcodeXCHG*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_XLAT:
                sum += ((GOpcodeXLAT*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_LEA:
                sum += ((GOpcodeLEA*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_LDS:
                sum += ((GOpcodeLDS*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_LES:
                sum += ((GOpcodeLES*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_LAHF:
                sum += ((GOpcodeLAHF*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_SAHF:
                sum += ((GOpcodeSAHF*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_PUSH:
                sum += ((GOpcodePUSH*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_POP:
                sum += ((GOpcodePOP*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_PUSHF:
                sum += ((GOpcodePUSHF*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_POPF:
                sum += ((GOpcodePOPF*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_IN:
                sum += ((GOpcodeIN*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_OUT:
                sum += ((GOpcodeOUT*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_ADD:
                sum += ((GOpcodeADD*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_ADC:
                sum += ((GOpcodeADC*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_SUB:
                sum += ((GOpcodeSUB*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_SBB:
                sum += ((GOpcodeSBB*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_CMP:
                sum += ((GOpcodeCMP*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_MUL:
                sum += ((GOpcodeMUL*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_IMUL:
                sum += ((GOpcodeIMUL*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_DIV:
                sum += ((GOpcodeDIV*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_IDIV:
                sum += ((GOpcodeIDIV*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_INC:
                sum += ((GOpcodeINC*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_DEC:
                sum += ((GOpcodeDEC*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_NEG:
                sum += ((GOpcodeNEG*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_CBW:
                sum += ((GOpcodeCBW*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_CWD:
                sum += ((GOpcodeCWD*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_DAA:
                sum += ((GOpcodeDAA*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_DAS:
                sum += ((GOpcodeDAS*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_AAA:
                sum += ((GOpcodeAAA*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_AAS:
                sum += ((GOpcodeAAS*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_AAM:
                sum += ((GOpcodeAAM*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_AAD:
                sum += ((GOpcodeAAD*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_AND:
                sum += ((GOpcodeAND*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_OR:
                sum += ((GOpcodeOR*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_XOR:
                sum += ((GOpcodeXOR*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_NOT:
                sum += ((GOpcodeNOT*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_TEST:
                sum += ((GOpcodeTEST*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_RCL:
                sum += ((GOpcodeRCL*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_RCR:
                sum += ((GOpcodeRCR*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_ROL:
                sum += ((GOpcodeROL*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_ROR:
                sum += ((GOpcodeROR*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_SAL:
                sum += ((GOpcodeSAL*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_SAR:
                sum += ((GOpcodeSAR*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_SHL:
                sum += ((GOpcodeSHL*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_SHR:
                sum += ((GOpcodeSHR*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_BT:
                sum += ((GOpcodeBT*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_BTC:
                sum += ((GOpcodeBTC*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_BTR:
                sum += ((GOpcodeBTR*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_BTS:
                sum += ((GOpcodeBTS*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_JMP:
                sum += ((GOpcodeJMP*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_CALL:
                sum += ((GOpcodeCALL*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_RET:
                sum += ((GOpcodeRET*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_JL:
                sum += ((GOpcodeJL*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_JNGE:
                sum += ((GOpcodeJNGE*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_JNL:
                sum += ((GOpcodeJNL*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_JGE:
                sum += ((GOpcodeJGE*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_JLE:
                sum += ((GOpcodeJLE*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_JNG:
                sum += ((GOpcodeJNG*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_JNLE:
                sum += ((GOpcodeJNLE*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_JG:
                sum += ((GOpcodeJG*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_JB:
                sum += ((GOpcodeJB*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_JNAE:
                sum += ((GOpcodeJNAE*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_JC:
                sum += ((GOpcodeJC*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_JBE:
                sum += ((GOpcodeJBE*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_JNA:
                sum += ((GOpcodeJNA*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_JNB:
                sum += ((GOpcodeJNB*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_JAE:
                sum += ((GOpcodeJAE*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_JNC:
                sum += ((GOpcodeJNC*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_JNBE:
                sum += ((GOpcodeJNBE*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_JA:
                sum += ((GOpcodeJA*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_JE:
                sum += ((GOpcodeJE*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_JZ:
                sum += ((GOpcodeJZ*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_JP:
                sum += ((GOpcodeJP*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_JPE:
                sum += ((GOpcodeJPE*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_JO:
                sum += ((GOpcodeJO*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_JS:
                sum += ((GOpcodeJS*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_JNE:
                sum += ((GOpcodeJNE*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_JNZ:
                sum += ((GOpcodeJNZ*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_JNP:
                sum += ((GOpcodeJNP*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_JPO:
                sum += ((GOpcodeJPO*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_JNO:
                sum += ((GOpcodeJNO*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_JNS:
                sum += ((GOpcodeJNS*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_JCXZ:
                sum += ((GOpcodeJCXZ*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_LOOP:
                sum += ((GOpcodeLOOP*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_LOOPE:
                sum += ((GOpcodeLOOPE*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_LOOPZ:
                sum += ((GOpcodeLOOPZ*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_LOOPNE:
                sum += ((GOpcodeLOOPNE*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_LOOPNZ:
                sum += ((GOpcodeLOOPNZ*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_INT:
                sum += ((GOpcodeINT*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_INTO:
                sum += ((GOpcodeINTO*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_CLC:
                sum += ((GOpcodeCLC*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_STC:
                sum += ((GOpcodeSTC*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_CMC:
                sum += ((GOpcodeCMC*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_CLD:
                sum += ((GOpcodeCLD*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_STD:
                sum += ((GOpcodeSTD*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_CLI:
                sum += ((GOpcodeCLI*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_STI:
                sum += ((GOpcodeSTI*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_HLT:
                sum += ((GOpcodeHLT*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_WAIT:
                sum += ((GOpcodeWAIT*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_LOCK:
                sum += ((GOpcodeLOCK*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_ESC:
                sum += ((GOpcodeESC*)(*it)->sourceStringBase())->ticks();
                break;
            case OPCODE_NOP:
                sum += ((GOpcodeNOP*)(*it)->sourceStringBase())->ticks();
                break;
//            case OPCODE_REP_MOVS:
//                sum += ((GOpcodeREP_MOVS*)(*it)->sourceStringBase())->ticks();
//                break;
//            case OPCODE_REP_STOS:
//                sum += ((GOpcodeREP_STOS*)(*it)->sourceStringBase())->ticks();
//                break;
//            case OPCODE_REPE_CMPS:
//                sum += ((GOpcodeREPE_CMPS*)(*it)->sourceStringBase())->ticks();
//                break;
//            case OPCODE_REPE_SCAS:
//                sum += ((GOpcodeREPE_SCAS*)(*it)->sourceStringBase())->ticks();
//                break;
//            case OPCODE_REPZ_CMPS:
//                sum += ((GOpcodeREPZ_CMPS*)(*it)->sourceStringBase())->ticks();
//                break;
//            case OPCODE_REPZ_SCAS:
//                sum += ((GOpcodeREPZ_SCAS*)(*it)->sourceStringBase())->ticks();
//                break;
//            case OPCODE_REPNE_MOVS:
//                sum += ((GOpcodeREPNE_MOVS*)(*it)->sourceStringBase())->ticks();
//                break;
//            case OPCODE_REPNE_STOS:
//                sum += ((GOpcodeREPNE_STOS*)(*it)->sourceStringBase())->ticks();
//                break;
//            case OPCODE_REPNZ_CMPS:
//                sum += ((GOpcodeREPNZ_CMPS*)(*it)->sourceStringBase())->ticks();
//                break;
//            case OPCODE_REPNZ_SCAS:
//                sum += ((GOpcodeREPNZ_SCAS*)(*it)->sourceStringBase())->ticks();
//                break;
            }
        }// if ((*it)->numberOfLine() >= from && (*it)->numberOfLine() <= to)

    }// for(it = m_pstrsSrc->begin(); it != m_pstrsSrc->end(); ++it)

    return(sum);
}

int GSourceCode::getCommonBytes(void){

    return getBytesBetweenLines(1, m_pstrsSrc->count());
}

int GSourceCode::getBytesBetweenLines(int from, int to){
    int sum(0);
    SourceStringType SSType;

    fullAnalyse();

    QVector<GSourceString*>::iterator it;// = m_pstrsSrc->begin();

    for(it = m_pstrsSrc->begin(); it != m_pstrsSrc->end(); ++it){

        if ((*it)->numberOfLine() >= from && (*it)->numberOfLine() <= to) {

        SSType = (*it)->m_SSType;

        switch(SSType){
            case LABEL_GLOBAL:
                sum += 0;
                break;
            case LABEL_LOCAL:
                sum += 0;
                break;
            case LABEL_UNNAMED:
                sum += 0;
                break;
            case DATA_SINGLE:
                sum += 0;
                break;
            case DATA_DUP:
                sum += 0;
                break;
            case COMMENT:
                sum += 0;
                break;
            case OPCODE_MOV:
                sum += ((GOpcodeMOV*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_XCHG:
                sum += ((GOpcodeXCHG*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_XLAT:
                sum += ((GOpcodeXLAT*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_LEA:
                sum += ((GOpcodeLEA*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_LDS:
                sum += ((GOpcodeLDS*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_LES:
                sum += ((GOpcodeLES*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_LAHF:
                sum += ((GOpcodeLAHF*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_SAHF:
                sum += ((GOpcodeSAHF*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_PUSH:
                sum += ((GOpcodePUSH*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_POP:
                sum += ((GOpcodePOP*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_PUSHF:
                sum += ((GOpcodePUSHF*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_POPF:
                sum += ((GOpcodePOPF*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_IN:
                sum += ((GOpcodeIN*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_OUT:
                sum += ((GOpcodeOUT*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_ADD:
                sum += ((GOpcodeADD*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_ADC:
                sum += ((GOpcodeADC*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_SUB:
                sum += ((GOpcodeSUB*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_SBB:
                sum += ((GOpcodeSBB*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_CMP:
                sum += ((GOpcodeCMP*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_MUL:
                sum += ((GOpcodeMUL*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_IMUL:
                sum += ((GOpcodeIMUL*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_DIV:
                sum += ((GOpcodeDIV*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_IDIV:
                sum += ((GOpcodeIDIV*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_INC:
                sum += ((GOpcodeINC*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_DEC:
                sum += ((GOpcodeDEC*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_NEG:
                sum += ((GOpcodeNEG*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_CBW:
                sum += ((GOpcodeCBW*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_CWD:
                sum += ((GOpcodeCWD*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_DAA:
                sum += ((GOpcodeDAA*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_DAS:
                sum += ((GOpcodeDAS*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_AAA:
                sum += ((GOpcodeAAA*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_AAS:
                sum += ((GOpcodeAAS*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_AAM:
                sum += ((GOpcodeAAM*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_AAD:
                sum += ((GOpcodeAAD*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_AND:
                sum += ((GOpcodeAND*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_OR:
                sum += ((GOpcodeOR*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_XOR:
                sum += ((GOpcodeXOR*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_NOT:
                sum += ((GOpcodeNOT*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_TEST:
                sum += ((GOpcodeTEST*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_RCL:
                sum += ((GOpcodeRCL*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_RCR:
                sum += ((GOpcodeRCR*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_ROL:
                sum += ((GOpcodeROL*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_ROR:
                sum += ((GOpcodeROR*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_SAL:
                sum += ((GOpcodeSAL*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_SAR:
                sum += ((GOpcodeSAR*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_SHL:
                sum += ((GOpcodeSHL*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_SHR:
                sum += ((GOpcodeSHR*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_BT:
                sum += ((GOpcodeBT*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_BTC:
                sum += ((GOpcodeBTC*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_BTR:
                sum += ((GOpcodeBTR*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_BTS:
                sum += ((GOpcodeBTS*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_JMP:
                sum += ((GOpcodeJMP*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_CALL:
                sum += ((GOpcodeCALL*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_RET:
                sum += ((GOpcodeRET*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_JL:
                sum += ((GOpcodeJL*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_JNGE:
                sum += ((GOpcodeJNGE*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_JNL:
                sum += ((GOpcodeJNL*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_JGE:
                sum += ((GOpcodeJGE*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_JLE:
                sum += ((GOpcodeJLE*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_JNG:
                sum += ((GOpcodeJNG*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_JNLE:
                sum += ((GOpcodeJNLE*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_JG:
                sum += ((GOpcodeJG*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_JB:
                sum += ((GOpcodeJB*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_JNAE:
                sum += ((GOpcodeJNAE*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_JC:
                sum += ((GOpcodeJC*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_JBE:
                sum += ((GOpcodeJBE*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_JNA:
                sum += ((GOpcodeJNA*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_JNB:
                sum += ((GOpcodeJNB*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_JAE:
                sum += ((GOpcodeJAE*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_JNC:
                sum += ((GOpcodeJNC*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_JNBE:
                sum += ((GOpcodeJNBE*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_JA:
                sum += ((GOpcodeJA*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_JE:
                sum += ((GOpcodeJE*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_JZ:
                sum += ((GOpcodeJZ*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_JP:
                sum += ((GOpcodeJP*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_JPE:
                sum += ((GOpcodeJPE*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_JO:
                sum += ((GOpcodeJO*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_JS:
                sum += ((GOpcodeJS*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_JNE:
                sum += ((GOpcodeJNE*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_JNZ:
                sum += ((GOpcodeJNZ*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_JNP:
                sum += ((GOpcodeJNP*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_JPO:
                sum += ((GOpcodeJPO*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_JNO:
                sum += ((GOpcodeJNO*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_JNS:
                sum += ((GOpcodeJNS*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_JCXZ:
                sum += ((GOpcodeJCXZ*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_LOOP:
                sum += ((GOpcodeLOOP*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_LOOPE:
                sum += ((GOpcodeLOOPE*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_LOOPZ:
                sum += ((GOpcodeLOOPZ*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_LOOPNE:
                sum += ((GOpcodeLOOPNE*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_LOOPNZ:
                sum += ((GOpcodeLOOPNZ*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_INT:
                sum += ((GOpcodeINT*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_INTO:
                sum += ((GOpcodeINTO*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_CLC:
                sum += ((GOpcodeCLC*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_STC:
                sum += ((GOpcodeSTC*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_CMC:
                sum += ((GOpcodeCMC*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_CLD:
                sum += ((GOpcodeCLD*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_STD:
                sum += ((GOpcodeSTD*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_CLI:
                sum += ((GOpcodeCLI*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_STI:
                sum += ((GOpcodeSTI*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_HLT:
                sum += ((GOpcodeHLT*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_WAIT:
                sum += ((GOpcodeWAIT*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_LOCK:
                sum += ((GOpcodeLOCK*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_ESC:
                sum += ((GOpcodeESC*)(*it)->sourceStringBase())->bytes();
                break;
            case OPCODE_NOP:
                sum += ((GOpcodeNOP*)(*it)->sourceStringBase())->bytes();
                break;
//            case OPCODE_REP_MOVS:
//                sum += ((GOpcodeREP_MOVS*)(*it)->sourceStringBase())->bytes();
//                break;
//            case OPCODE_REP_STOS:
//                sum += ((GOpcodeREP_STOS*)(*it)->sourceStringBase())->bytes();
//                break;
//            case OPCODE_REPE_CMPS:
//                sum += ((GOpcodeREPE_CMPS*)(*it)->sourceStringBase())->bytes();
//                break;
//            case OPCODE_REPE_SCAS:
//                sum += ((GOpcodeREPE_SCAS*)(*it)->sourceStringBase())->bytes();
//                break;
//            case OPCODE_REPZ_CMPS:
//                sum += ((GOpcodeREPZ_CMPS*)(*it)->sourceStringBase())->bytes();
//                break;
//            case OPCODE_REPZ_SCAS:
//                sum += ((GOpcodeREPZ_SCAS*)(*it)->sourceStringBase())->bytes();
//                break;
//            case OPCODE_REPNE_MOVS:
//                sum += ((GOpcodeREPNE_MOVS*)(*it)->sourceStringBase())->bytes();
//                break;
//            case OPCODE_REPNE_STOS:
//                sum += ((GOpcodeREPNE_STOS*)(*it)->sourceStringBase())->bytes();
//                break;
//            case OPCODE_REPNZ_CMPS:
//                sum += ((GOpcodeREPNZ_CMPS*)(*it)->sourceStringBase())->bytes();
//                break;
//            case OPCODE_REPNZ_SCAS:
//              sum += ((GOpcodeREPNZ_SCAS*)(*it)->sourceStringBase())->bytes();
//                break;
            }

        }// if ((*it)->numberOfLine() >= from && (*it)->numberOfLine() <= to)
    }

    return(sum);
}

QPair<int, int>* GSourceCode::getFirstCycleFrom(int fromLine){

    int cycle_begin(-1);
    int cycle_end(-1);
    QString label_name;
    SourceStringType SSType;

    typedef QVector<GSourceString*>::const_iterator CIT;

    for (CIT it = m_pstrsSrc->begin(); it != m_pstrsSrc->end(); ++it) {

        if ((*it)->numberOfLine() >= fromLine) {
            SSType = (*it)->m_SSType;

            switch(SSType){
            case OPCODE_JMP:
                label_name = ((GOpcodeJMP*)(*it)->sourceStringBase())->op1();

                break;
            case OPCODE_JL:
                label_name = ((GOpcodeJL*)(*it)->sourceStringBase())->op1();
                break;
            case OPCODE_JNGE:
                label_name = ((GOpcodeJNGE*)(*it)->sourceStringBase())->op1();
                break;
            case OPCODE_JNL:
                label_name = ((GOpcodeJNL*)(*it)->sourceStringBase())->op1();
                break;
            case OPCODE_JGE:
                label_name = ((GOpcodeJGE*)(*it)->sourceStringBase())->op1();
                break;
            case OPCODE_JLE:
                label_name = ((GOpcodeJLE*)(*it)->sourceStringBase())->op1();
                break;
            case OPCODE_JNG:
                label_name = ((GOpcodeJNG*)(*it)->sourceStringBase())->op1();
                break;
            case OPCODE_JNLE:
                label_name = ((GOpcodeJNLE*)(*it)->sourceStringBase())->op1();
                break;
            case OPCODE_JG:
                label_name = ((GOpcodeJG*)(*it)->sourceStringBase())->op1();
                break;
            case OPCODE_JB:
                label_name = ((GOpcodeJB*)(*it)->sourceStringBase())->op1();
                break;
            case OPCODE_JNAE:
                label_name = ((GOpcodeJNAE*)(*it)->sourceStringBase())->op1();
                break;
            case OPCODE_JC:
                label_name = ((GOpcodeJC*)(*it)->sourceStringBase())->op1();
                break;
            case OPCODE_JBE:
                label_name = ((GOpcodeJBE*)(*it)->sourceStringBase())->op1();
                break;
            case OPCODE_JNA:
                label_name = ((GOpcodeJNA*)(*it)->sourceStringBase())->op1();
                break;
            case OPCODE_JNB:
                label_name = ((GOpcodeJNB*)(*it)->sourceStringBase())->op1();
                break;
            case OPCODE_JAE:
                label_name = ((GOpcodeJAE*)(*it)->sourceStringBase())->op1();
                break;
            case OPCODE_JNC:
                label_name = ((GOpcodeJNC*)(*it)->sourceStringBase())->op1();
                break;
            case OPCODE_JNBE:
                label_name = ((GOpcodeJNBE*)(*it)->sourceStringBase())->op1();
                break;
            case OPCODE_JA:
                label_name = ((GOpcodeJA*)(*it)->sourceStringBase())->op1();
                break;
            case OPCODE_JE:
                label_name = ((GOpcodeJE*)(*it)->sourceStringBase())->op1();
                break;
            case OPCODE_JZ:
                label_name = ((GOpcodeJZ*)(*it)->sourceStringBase())->op1();
                break;
            case OPCODE_JP:
                label_name = ((GOpcodeJP*)(*it)->sourceStringBase())->op1();
                break;
            case OPCODE_JPE:
                label_name = ((GOpcodeJPE*)(*it)->sourceStringBase())->op1();
                break;
            case OPCODE_JO:
                label_name = ((GOpcodeJO*)(*it)->sourceStringBase())->op1();
                break;
            case OPCODE_JS:
                label_name = ((GOpcodeJS*)(*it)->sourceStringBase())->op1();
                break;
            case OPCODE_JNE:
                label_name = ((GOpcodeJNE*)(*it)->sourceStringBase())->op1();
                break;
            case OPCODE_JNZ:
                label_name = ((GOpcodeJNZ*)(*it)->sourceStringBase())->op1();
                break;
            case OPCODE_JNP:
                label_name = ((GOpcodeJNP*)(*it)->sourceStringBase())->op1();
                break;
            case OPCODE_JPO:
                label_name = ((GOpcodeJPO*)(*it)->sourceStringBase())->op1();
                break;
            case OPCODE_JNO:
                label_name = ((GOpcodeJNO*)(*it)->sourceStringBase())->op1();
                break;
            case OPCODE_JNS:
                label_name = ((GOpcodeJNS*)(*it)->sourceStringBase())->op1();
                break;
            case OPCODE_JCXZ:
                label_name = ((GOpcodeJCXZ*)(*it)->sourceStringBase())->op1();
                break;
            case OPCODE_LOOP:
                label_name = ((GOpcodeLOOP*)(*it)->sourceStringBase())->op1();
                break;
            case OPCODE_LOOPE:
                label_name = ((GOpcodeLOOPE*)(*it)->sourceStringBase())->op1();
                break;
            case OPCODE_LOOPZ:
                label_name = ((GOpcodeLOOPZ*)(*it)->sourceStringBase())->op1();
                break;
            case OPCODE_LOOPNE:
                label_name = ((GOpcodeLOOPNE*)(*it)->sourceStringBase())->op1();
                break;
            case OPCODE_LOOPNZ:
                label_name = ((GOpcodeLOOPNZ*)(*it)->sourceStringBase())->op1();
                break;
            default:
                ;
            }

        }//if ((*it)->numberOfLine() >= fromLine)

        if (label_name.length() != 0) {

            cycle_end = (*it)->numberOfLine();
            break;
        }

    }//for (CIT it = m_pstrsSrc->begin(); it != m_pstrsSrc->end(); ++it)

    QString label_name_tmp;

    for (CIT it = m_pstrsSrc->begin(); it != m_pstrsSrc->end(); ++it) {

        if ((*it)->numberOfLine() >= fromLine) {

            SSType = (*it)->m_SSType;

            switch(SSType){
            case LABEL_GLOBAL:
                label_name_tmp = ((GLabelGlobal*)(*it)->sourceStringBase())->labelName();
                break;
            case LABEL_LOCAL:
                label_name_tmp = ((GLabelLocal*)(*it)->sourceStringBase())->labelName();
                break;
            default:
                ;
            }
        }

        if (label_name_tmp.length() != 0) {

            if (label_name_tmp == label_name) {

                if ((*it)->numberOfLine() < cycle_end) {

                    cycle_begin = (*it)->numberOfLine();
                    break;
                }
            }
        }

    }//for (CIT it = m_pstrsSrc->begin(); it != m_pstrsSrc->end(); ++it)

    if (cycle_begin != -1 && cycle_end != -1) {

        return new QPair<int, int>(cycle_begin, cycle_end);
    }
    else {

        return new QPair<int, int>(-1, -1);
    }
}

QVector<QPair<int, int> *> *GSourceCode::getAllCycles(){

    int line(1);
    QVector<QPair<int, int>* >* theVec = new QVector<QPair<int, int>* >();
    QPair<int, int>* thePair = getFirstCycleFrom(line);
    while (thePair->first != -1 && thePair->second != -1) {

        theVec->push_back(thePair);
        line = thePair->second + 1;
        thePair = getFirstCycleFrom(line);
    }

    return theVec;
}

void GSourceCode::fullAnalyse(void){

    SourceStringType SSType;

    QVector<GSourceString*>::iterator it;// = m_pstrsSrc->begin();

    for(it = m_pstrsSrc->begin(); it != m_pstrsSrc->end(); ++it){
        SSType = (*it)->m_SSType;

        switch(SSType){
        case OPCODE_MOV:
            ((GOpcodeMOV*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_XCHG:
            ((GOpcodeXCHG*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_XLAT:
            ((GOpcodeXLAT*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_LEA:
            ((GOpcodeLEA*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_LDS:
            ((GOpcodeLDS*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_LES:
            ((GOpcodeLES*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_LAHF:
            ((GOpcodeLAHF*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_SAHF:
            ((GOpcodeSAHF*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_PUSH:
            ((GOpcodePUSH*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_POP:
            ((GOpcodePOP*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_PUSHF:
            ((GOpcodePUSHF*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_POPF:
            ((GOpcodePOPF*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_IN:
            ((GOpcodeIN*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_OUT:
            ((GOpcodeOUT*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_ADD:
            ((GOpcodeADD*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_ADC:
            ((GOpcodeADC*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_SUB:
            ((GOpcodeSUB*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_SBB:
            ((GOpcodeSBB*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_CMP:
            ((GOpcodeCMP*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_MUL:
            ((GOpcodeMUL*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_IMUL:
            ((GOpcodeIMUL*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_DIV:
            ((GOpcodeDIV*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_IDIV:
            ((GOpcodeIDIV*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_INC:
            ((GOpcodeINC*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_DEC:
            ((GOpcodeDEC*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_NEG:
            ((GOpcodeNEG*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_CBW:
            ((GOpcodeCBW*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_CWD:
            ((GOpcodeCWD*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_DAA:
            ((GOpcodeDAA*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_DAS:
            ((GOpcodeDAS*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_AAA:
            ((GOpcodeAAA*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_AAS:
            ((GOpcodeAAS*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_AAM:
            ((GOpcodeAAM*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_AAD:
            ((GOpcodeAAD*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_AND:
            ((GOpcodeAND*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_OR:
            ((GOpcodeOR*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_XOR:
            ((GOpcodeXOR*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_NOT:
            ((GOpcodeNOT*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_TEST:
            ((GOpcodeTEST*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_RCL:
            ((GOpcodeRCL*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_RCR:
            ((GOpcodeRCR*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_ROL:
            ((GOpcodeROL*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_ROR:
            ((GOpcodeROR*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_SAL:
            ((GOpcodeSAL*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_SAR:
            ((GOpcodeSAR*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_SHL:
            ((GOpcodeSHL*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_SHR:
            ((GOpcodeSHR*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_BT:
            ((GOpcodeBT*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_BTC:
            ((GOpcodeBTC*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_BTR:
            ((GOpcodeBTR*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_BTS:
            ((GOpcodeBTS*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_JMP:
            ((GOpcodeJMP*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_CALL:
            ((GOpcodeCALL*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_RET:
            ((GOpcodeRET*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_JL:
            ((GOpcodeJL*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_JNGE:
            ((GOpcodeJNGE*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_JNL:
            ((GOpcodeJNL*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_JGE:
            ((GOpcodeJGE*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_JLE:
            ((GOpcodeJLE*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_JNG:
            ((GOpcodeJNG*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_JNLE:
            ((GOpcodeJNLE*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_JG:
            ((GOpcodeJG*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_JB:
            ((GOpcodeJB*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_JNAE:
            ((GOpcodeJNAE*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_JC:
            ((GOpcodeJC*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_JBE:
            ((GOpcodeJBE*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_JNA:
            ((GOpcodeJNA*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_JNB:
            ((GOpcodeJNB*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_JAE:
            ((GOpcodeJAE*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_JNC:
            ((GOpcodeJNC*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_JNBE:
            ((GOpcodeJNBE*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_JA:
            ((GOpcodeJA*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_JE:
            ((GOpcodeJE*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_JZ:
            ((GOpcodeJZ*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_JP:
            ((GOpcodeJP*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_JPE:
            ((GOpcodeJPE*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_JO:
            ((GOpcodeJO*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_JS:
            ((GOpcodeJS*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_JNE:
            ((GOpcodeJNE*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_JNZ:
            ((GOpcodeJNZ*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_JNP:
            ((GOpcodeJNP*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_JPO:
            ((GOpcodeJPO*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_JNO:
            ((GOpcodeJNO*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_JNS:
            ((GOpcodeJNS*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_JCXZ:
            ((GOpcodeJCXZ*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_LOOP:
            ((GOpcodeLOOP*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_LOOPE:
            ((GOpcodeLOOPE*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_LOOPZ:
            ((GOpcodeLOOPZ*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_LOOPNE:
            ((GOpcodeLOOPNE*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_LOOPNZ:
            ((GOpcodeLOOPNZ*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_INT:
            ((GOpcodeINT*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_INTO:
            ((GOpcodeINTO*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_CLC:
            ((GOpcodeCLC*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_STC:
            ((GOpcodeSTC*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_CMC:
            ((GOpcodeCMC*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_CLD:
            ((GOpcodeCLD*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_STD:
            ((GOpcodeSTD*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_CLI:
            ((GOpcodeCLI*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_STI:
            ((GOpcodeSTI*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_HLT:
            ((GOpcodeHLT*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_WAIT:
            ((GOpcodeWAIT*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_LOCK:
            ((GOpcodeLOCK*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_ESC:
            ((GOpcodeESC*)(*it)->sourceStringBase())->analyse();
            break;
        case OPCODE_NOP:
            ((GOpcodeNOP*)(*it)->sourceStringBase())->analyse();
            break;
//        case OPCODE_REP_MOVS:
//            ((GOpcodeREP_MOVS*)(*it)->sourceStringBase())->analyse();
//            break;
//        case OPCODE_REP_STOS:
//            ((GOpcodeREP_STOS*)(*it)->sourceStringBase())->analyse();
//            break;
//        case OPCODE_REPE_CMPS:
//            ((GOpcodeREPE_CMPS*)(*it)->sourceStringBase())->analyse();
//            break;
//        case OPCODE_REPE_SCAS:
//            ((GOpcodeREPE_SCAS*)(*it)->sourceStringBase())->analyse();
//            break;
//        case OPCODE_REPZ_CMPS:
//            ((GOpcodeREPZ_CMPS*)(*it)->sourceStringBase())->analyse();
//            break;
//        case OPCODE_REPZ_SCAS:
//            ((GOpcodeREPZ_SCAS*)(*it)->sourceStringBase())->analyse();
//            break;
//        case OPCODE_REPNE_MOVS:
//            ((GOpcodeREPNE_MOVS*)(*it)->sourceStringBase())->analyse();
//            break;
//        case OPCODE_REPNE_STOS:
//            ((GOpcodeREPNE_STOS*)(*it)->sourceStringBase())->analyse();
//            break;
//        case OPCODE_REPNZ_CMPS:
//            ((GOpcodeREPNZ_CMPS*)(*it)->sourceStringBase())->analyse();
//            break;
//        case OPCODE_REPNZ_SCAS:
//            ((GOpcodeREPNZ_SCAS*)(*it)->sourceStringBase())->analyse();
//            break;
        default:
            break;
        }
    }
}
