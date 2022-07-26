#include "libraries/galactic_unicorn/galactic_unicorn.hpp"
#include "micropython/modules/util.hpp"
#include <cstdio>
#include <cfloat>


using namespace pimoroni;

extern "C" {
#include "galactic_unicorn.h"
#include "py/builtin.h"


/********** GalacticUnicorn **********/

/***** Variables Struct *****/
typedef struct _GalacticUnicorn_obj_t {
    mp_obj_base_t base;
    GalacticUnicorn* galactic;
} _GalacticUnicorn_obj_t;


/***** Print *****/
void GalacticUnicorn_print(const mp_print_t *print, mp_obj_t self_in, mp_print_kind_t kind) {
    (void)kind; //Unused input parameter
    //_GalacticUnicorn_obj_t *self = MP_OBJ_TO_PTR2(self_in, _GalacticUnicorn_obj_t);
    mp_print_str(print, "GalacticUnicorn()");
}


/***** Constructor *****/
mp_obj_t GalacticUnicorn_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *all_args) {
    _GalacticUnicorn_obj_t *self = nullptr;

    enum { ARG_pio, ARG_sm, ARG_pins, ARG_common_pin, ARG_direction, ARG_counts_per_rev, ARG_count_microsteps, ARG_freq_divider };
    static const mp_arg_t allowed_args[] = {
        { MP_QSTR_pio, MP_ARG_INT },
        { MP_QSTR_sm, MP_ARG_INT }
    };

    // Parse args.
    mp_arg_val_t args[MP_ARRAY_SIZE(allowed_args)];
    mp_arg_parse_all_kw_array(n_args, n_kw, all_args, MP_ARRAY_SIZE(allowed_args), allowed_args, args);

    int pio_int = args[ARG_pio].u_int;
    if(pio_int < 0 || pio_int > (int)NUM_PIOS) {
        mp_raise_ValueError("pio out of range. Expected 0 to 1");
    }
    //PIO pio = pio_int == 0 ? pio0 : pio1;

    int sm = args[ARG_sm].u_int;
    if(sm < 0 || sm > (int)NUM_PIO_STATE_MACHINES) {
        mp_raise_ValueError("sm out of range. Expected 0 to 3");
    }


    GalacticUnicorn *galactic = m_new_class(GalacticUnicorn);
    galactic->init();
    //if(!galactic->init()) {
        //m_del_class(GalacticUnicorn, galactic);
        //mp_raise_msg(&mp_type_RuntimeError, "unable to allocate the hardware resources needed to initialise this GalacticUnicorn. Try running `import gc` followed by `gc.collect()` before creating it");
    //}

    self = m_new_obj_with_finaliser(_GalacticUnicorn_obj_t);
    self->base.type = &GalacticUnicorn_type;
    self->galactic = galactic;

    return MP_OBJ_FROM_PTR(self);
}


/***** Destructor ******/
mp_obj_t GalacticUnicorn___del__(mp_obj_t self_in) {
    _GalacticUnicorn_obj_t *self = MP_OBJ_TO_PTR2(self_in, _GalacticUnicorn_obj_t);
    m_del_class(GalacticUnicorn, self->galactic);
    return mp_const_none;
}


/***** Methods *****/
extern mp_obj_t GalacticUnicorn_clear(mp_obj_t self_in) {
    //_GalacticUnicorn_obj_t *self = MP_OBJ_TO_PTR2(self_in, _GalacticUnicorn_obj_t);
    //self->galactic->clear();
    return mp_const_none;
}

extern mp_obj_t GalacticUnicorn_update(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args) {
    //_GalacticUnicorn_obj_t *self = MP_OBJ_TO_PTR2(self_in, _GalacticUnicorn_obj_t);
    return mp_const_none;
}

extern mp_obj_t GalacticUnicorn_set_brightness(mp_obj_t self_in, mp_obj_t value) {
    //_GalacticUnicorn_obj_t *self = MP_OBJ_TO_PTR2(self_in, _GalacticUnicorn_obj_t);
    return mp_const_none;
}

extern mp_obj_t GalacticUnicorn_get_brightness(mp_obj_t self_in) {
//_GalacticUnicorn_obj_t *self = MP_OBJ_TO_PTR2(self_in, _GalacticUnicorn_obj_t);
    return mp_const_none;
}

extern mp_obj_t GalacticUnicorn_adjust_brightness(mp_obj_t self_in, mp_obj_t delta) {
    //_GalacticUnicorn_obj_t *self = MP_OBJ_TO_PTR2(self_in, _GalacticUnicorn_obj_t);
    return mp_const_none;
}

extern mp_obj_t GalacticUnicorn_set_volume(mp_obj_t self_in, mp_obj_t value) {
    //_GalacticUnicorn_obj_t *self = MP_OBJ_TO_PTR2(self_in, _GalacticUnicorn_obj_t);
    return mp_const_none;
}

extern mp_obj_t GalacticUnicorn_get_volume(mp_obj_t self_in) {
    //_GalacticUnicorn_obj_t *self = MP_OBJ_TO_PTR2(self_in, _GalacticUnicorn_obj_t);
    return mp_const_none;
}

extern mp_obj_t GalacticUnicorn_adjust_volume(mp_obj_t self_in, mp_obj_t delta) {
//_GalacticUnicorn_obj_t *self = MP_OBJ_TO_PTR2(self_in, _GalacticUnicorn_obj_t);
    return mp_const_none;
}

extern mp_obj_t GalacticUnicorn_set_pixel(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args) {
//_GalacticUnicorn_obj_t *self = MP_OBJ_TO_PTR2(self_in, _GalacticUnicorn_obj_t);
    return mp_const_none;
}

extern mp_obj_t GalacticUnicorn_light(mp_obj_t self_in) {
//_GalacticUnicorn_obj_t *self = MP_OBJ_TO_PTR2(self_in, _GalacticUnicorn_obj_t);
    return mp_const_none;
}

extern mp_obj_t GalacticUnicorn_is_pressed(mp_obj_t self_in, mp_obj_t button) {
//_GalacticUnicorn_obj_t *self = MP_OBJ_TO_PTR2(self_in, _GalacticUnicorn_obj_t);
    return mp_const_none;
}

extern mp_obj_t GalacticUnicorn_play_sample(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args) {
    //_GalacticUnicorn_obj_t *self = MP_OBJ_TO_PTR2(self_in, _GalacticUnicorn_obj_t);
    return mp_const_none;
}
}
