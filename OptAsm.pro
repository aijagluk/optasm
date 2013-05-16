#-------------------------------------------------
#
# Project created by QtCreator 2012-07-25T07:15:57
#
#-------------------------------------------------

QT       += core gui

TARGET = OptAsm
TEMPLATE = app

greaterThan(QT_MAJOR_VERSION, 4) {
    QT += widgets
    DEFINES += HAVE_QT5 #\
               #QT_DISABLE_DEPRECATED_BEFORE=0
}

SOURCES += main.cpp\
        mainwindow.cpp \
    label_unnamed.cpp \
    label_local.cpp \
    label_global.cpp \
    directive.cpp \
    data_dup.cpp \
    data.cpp \
    comment.cpp \
    source_string.cpp \
    source_code.cpp \
    processor.cpp \
    opcode_mov.cpp \
    opcode_xchg.cpp \
    opcode_xlat.cpp \
    opcode_lea.cpp \
    opcode_lds.cpp \
    opcode_les.cpp \
    opcode_lahf.cpp \
    opcode_sahf.cpp \
    opcode_push.cpp \
    opcode_pop.cpp \
    opcode_pushf.cpp \
    opcode_popf.cpp \
    opcode_in.cpp \
    opcode_out.cpp \
    opcode_add.cpp \
    opcode_adc.cpp \
    opcode_sub.cpp \
    opcode_sbb.cpp \
    opcode_cmp.cpp \
    opcode_mul.cpp \
    opcode_imul.cpp \
    opcode_div.cpp \
    opcode_idiv.cpp \
    opcode_inc.cpp \
    opcode_dec.cpp \
    opcode_neg.cpp \
    opcode_cbw.cpp \
    opcode_cwd.cpp \
    opcode_daa.cpp \
    opcode_das.cpp \
    opcode_aaa.cpp \
    opcode_aas.cpp \
    opcode_aam.cpp \
    opcode_aad.cpp \
    opcode_and.cpp \
    opcode_or.cpp \
    opcode_xor.cpp \
    opcode_not.cpp \
    opcode_test.cpp \
    opcode_rcl.cpp \
    opcode_rcr.cpp \
    opcode_rol.cpp \
    opcode_ror.cpp \
    opcode_sal.cpp \
    opcode_sar.cpp \
    opcode_shl.cpp \
    opcode_shr.cpp \
    opcode_bt.cpp \
    opcode_btc.cpp \
    opcode_btr.cpp \
    opcode_bts.cpp \
    opcode_jmp.cpp \
    opcode_call.cpp \
    opcode_ret.cpp \
    opcode_jl.cpp \
    opcode_jnge.cpp \
    opcode_jnl.cpp \
    opcode_jge.cpp \
    opcode_jle.cpp \
    opcode_jng.cpp \
    opcode_jnle.cpp \
    opcode_jg.cpp \
    opcode_jb.cpp \
    opcode_jnae.cpp \
    opcode_jc.cpp \
    opcode_jbe.cpp \
    opcode_jna.cpp \
    opcode_jnb.cpp \
    opcode_jae.cpp \
    opcode_jnc.cpp \
    opcode_jnbe.cpp \
    opcode_ja.cpp \
    opcode_je.cpp \
    opcode_jz.cpp \
    opcode_jp.cpp \
    opcode_jpe.cpp \
    opcode_jo.cpp \
    opcode_js.cpp \
    opcode_jne.cpp \
    opcode_jnz.cpp \
    opcode_jnp.cpp \
    opcode_jpo.cpp \
    opcode_jno.cpp \
    opcode_jns.cpp \
    opcode_jcxz.cpp \
    opcode_loop.cpp \
    opcode_loope.cpp \
    opcode_loopz.cpp \
    opcode_loopne.cpp \
    opcode_loopnz.cpp \
    opcode_int.cpp \
    opcode_into.cpp \
    opcode_clc.cpp \
    opcode_stc.cpp \
    opcode_cmc.cpp \
    opcode_cld.cpp \
    opcode_std.cpp \
    opcode_cli.cpp \
    opcode_sti.cpp \
    opcode_hlt.cpp \
    opcode_wait.cpp \
    opcode_lock.cpp \
    opcode_esc.cpp \
    opcode_nop.cpp \
    opcode_rep_movs.cpp \
    opcode_rep_stos.cpp \
    opcode_repe_cmps.cpp \
    opcode_repe_scas.cpp \
    opcode_repz_cmps.cpp \
    opcode_repz_scas.cpp \
    opcode_repne_movs.cpp \
    opcode_repne_stos.cpp \
    opcode_repnz_cmps.cpp \
    opcode_repnz_scas.cpp

HEADERS  += mainwindow.h \
    validators.h \
    source_string.h \
    source_code.h \
    services_types.h \
    processor.h \
    opcode_mov.h \
    label_unnamed.h \
    label_local.h \
    label_global.h \
    directive.h \
    data_dup.h \
    data.h \
    comment.h \
    opcode_xchg.h \
    opcode_xlat.h \
    opcode_lea.h \
    opcode_lds.h \
    opcode_les.h \
    opcode_lahf.h \
    opcode_sahf.h \
    opcode_push.h \
    opcode_pop.h \
    opcode_pushf.h \
    opcode_popf.h \
    opcode_in.h \
    opcode_out.h \
    opcode_add.h \
    opcode_adc.h \
    opcode_sub.h \
    opcode_sbb.h \
    opcode_cmp.h \
    opcode_mul.h \
    opcode_imul.h \
    opcode_div.h \
    opcode_idiv.h \
    opcode_inc.h \
    opcode_dec.h \
    opcode_neg.h \
    opcode_cbw.h \
    opcode_cwd.h \
    opcode_daa.h \
    opcode_das.h \
    opcode_aaa.h \
    opcode_aas.h \
    opcode_aam.h \
    opcode_aad.h \
    opcode_and.h \
    opcode_or.h \
    opcode_xor.h \
    opcode_not.h \
    opcode_test.h \
    opcode_rcl.h \
    opcode_rcr.h \
    opcode_rol.h \
    opcode_ror.h \
    opcode_sal.h \
    opcode_sar.h \
    opcode_shl.h \
    opcode_shr.h \
    opcode_bt.h \
    opcode_btc.h \
    opcode_btr.h \
    opcode_bts.h \
    opcode_jmp.h \
    opcode_call.h \
    opcode_ret.h \
    opcode_jl.h \
    opcode_jnge.h \
    opcode_jnl.h \
    opcode_jge.h \
    opcode_jle.h \
    opcode_jng.h \
    opcode_jnle.h \
    opcode_jg.h \
    opcode_jb.h \
    opcode_jnae.h \
    opcode_jc.h \
    opcode_jbe.h \
    opcode_jna.h \
    opcode_jnb.h \
    opcode_jae.h \
    opcode_jnc.h \
    opcode_jnbe.h \
    opcode_ja.h \
    opcode_je.h \
    opcode_jz.h \
    opcode_jp.h \
    opcode_jpe.h \
    opcode_jo.h \
    opcode_js.h \
    opcode_jne.h \
    opcode_jnz.h \
    opcode_jnp.h \
    opcode_jpo.h \
    opcode_jno.h \
    opcode_jns.h \
    opcode_jcxz.h \
    opcode_loop.h \
    opcode_loope.h \
    opcode_loopz.h \
    opcode_loopne.h \
    opcode_loopnz.h \
    opcode_int.h \
    opcode_into.h \
    opcode_clc.h \
    opcode_stc.h \
    opcode_cmc.h \
    opcode_cld.h \
    opcode_std.h \
    opcode_cli.h \
    opcode_sti.h \
    opcode_hlt.h \
    opcode_wait.h \
    opcode_lock.h \
    opcode_esc.h \
    opcode_nop.h \
    opcode_rep_movs.h \
    opcode_rep_stos.h \
    opcode_repe_cmps.h \
    opcode_repe_scas.h \
    opcode_repz_cmps.h \
    opcode_repz_scas.h \
    opcode_repne_movs.h \
    opcode_repne_stos.h \
    opcode_repnz_cmps.h \
    opcode_repnz_scas.h

FORMS    += mainwindow.ui