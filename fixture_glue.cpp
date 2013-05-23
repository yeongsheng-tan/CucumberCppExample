/*
 * =====================================================================================
 *
 *       Filename:  feature_glue.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  22/05/2013 15:13:49
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *   Organization:
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "ruby.h"

using namespace std;
#include <stdio.h>

VALUE cRpnCalcFixture;

class RpnCalc {
  // this will actually be a production-class linked in
  // from a dynamic or static library (later)
};


void RpnCalcFixture_Dispose(void *c) {
    printf("Deleting calc\n");
    delete static_cast<RpnCalc*>(c);
}

VALUE RpnCalcFixture_New(VALUE clazz) {
    printf("Creating calc\n");
    RpnCalc *c = new RpnCalc;
    VALUE tdata = Data_Wrap_Struct(clazz, 0, RpnCalcFixture_Dispose, c);
    rb_obj_call_init(tdata, 0, 0);
    return tdata;
}

VALUE RpnCalcFixture_Enter(VALUE self, VALUE value) {
    printf("Enter value: %d\n", NUM2INT(value));
    return Qnil;
}

VALUE RpnCalcFixture_Perform(VALUE self, VALUE operatorName) {
    printf("Performing: %s\n", RSTRING_PTR(operatorName));
    return Qnil;
}

VALUE RpnCalcFixture_X(VALUE self) {
    printf("Getting x\n");
    return INT2NUM(12);
}

extern "C" {
typedef VALUE(*V_F)(...);
void Init_fixture_glue() {
    cRpnCalcFixture = rb_define_class("RpnCalcFixture", rb_cObject);
    rb_define_singleton_method(
            cRpnCalcFixture, "new", (V_F)RpnCalcFixture_New, 0);
    rb_define_method(cRpnCalcFixture, "x", (V_F)RpnCalcFixture_X, 0);
    rb_define_method(cRpnCalcFixture, "perform",(V_F)RpnCalcFixture_Perform, 1);
    rb_define_method(cRpnCalcFixture, "enter", (V_F)RpnCalcFixture_Enter, 1);
}
}