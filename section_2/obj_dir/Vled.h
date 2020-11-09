// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VLED_H_
#define _VLED_H_  // guard

#include "verilated.h"

//==========

class Vled__Syms;

//----------

VL_MODULE(Vled) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(i_clk,0,0);
    VL_OUT8(o_led,0,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    SData/*12:0*/ led__DOT__counter;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__i_clk;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vled__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vled);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vled(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vled();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vled__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vled__Syms* symsp, bool first);
  private:
    static QData _change_request(Vled__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vled__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vled__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vled__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__2(Vled__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vled__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(Vled__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
