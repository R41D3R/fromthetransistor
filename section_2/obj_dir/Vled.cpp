// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vled.h for the primary calling header

#include "Vled.h"
#include "Vled__Syms.h"

//==========

VL_CTOR_IMP(Vled) {
    Vled__Syms* __restrict vlSymsp = __VlSymsp = new Vled__Syms(this, name());
    Vled* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vled::__Vconfigure(Vled__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vled::~Vled() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vled::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vled::eval\n"); );
    Vled__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vled* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("led.v", 1, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vled::_eval_initial_loop(Vled__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("led.v", 1, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vled::_sequent__TOP__1(Vled__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vled::_sequent__TOP__1\n"); );
    Vled* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->led__DOT__counter = (0x1fffU & ((IData)(1U) 
                                            + (IData)(vlTOPp->led__DOT__counter)));
    vlTOPp->o_led = (1U & ((IData)(vlTOPp->led__DOT__counter) 
                           >> 0xcU));
}

void Vled::_initial__TOP__2(Vled__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vled::_initial__TOP__2\n"); );
    Vled* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->led__DOT__counter = 0U;
}

void Vled::_settle__TOP__3(Vled__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vled::_settle__TOP__3\n"); );
    Vled* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->o_led = (1U & ((IData)(vlTOPp->led__DOT__counter) 
                           >> 0xcU));
}

void Vled::_eval(Vled__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vled::_eval\n"); );
    Vled* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->i_clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__i_clk)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
    }
    // Final
    vlTOPp->__Vclklast__TOP__i_clk = vlTOPp->i_clk;
}

void Vled::_eval_initial(Vled__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vled::_eval_initial\n"); );
    Vled* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__i_clk = vlTOPp->i_clk;
    vlTOPp->_initial__TOP__2(vlSymsp);
}

void Vled::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vled::final\n"); );
    // Variables
    Vled__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vled* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vled::_eval_settle(Vled__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vled::_eval_settle\n"); );
    Vled* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

VL_INLINE_OPT QData Vled::_change_request(Vled__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vled::_change_request\n"); );
    Vled* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vled::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vled::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((i_clk & 0xfeU))) {
        Verilated::overWidthError("i_clk");}
}
#endif  // VL_DEBUG

void Vled::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vled::_ctor_var_reset\n"); );
    // Body
    i_clk = VL_RAND_RESET_I(1);
    o_led = VL_RAND_RESET_I(1);
    led__DOT__counter = VL_RAND_RESET_I(13);
}
