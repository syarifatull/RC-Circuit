typedef struct capacitor{
float cap; //kapasitansi
int vol_rating; // voltage rating
float init_value;//voltage initial value
} kap;

typedef struct resistor{
float res; // resistansi
int tol; // toleransi
int pow_rating; // power rating
} res;

typedef struct voltage{
float dc_voltage; // Tegangan DC
int ser_res; //resistansi seri
int cap_paralel; // kapasitansi paralel
int dc_offset; //Tegangan offset DC

int amp; // amplitudo
int freq; //frekuensi

int vol_init; // tegangan initial
int v_on; // tegangan ketika ON
int t_rise; // waktu ketika mulai v_on
int t_fall; // waktu ketika mulai v_init
int t_delay; // lama v_init / v_on bekerja sebelum berubah
int period; //periode gelombang
} vol_source;

typedef struct current{
int dc_current; // Arus DC
int dc_offset; //Arus offset DC

int amp; // amplitudo
int freq; //frekuensi

int i_init; // Arus initial
int i_on; // Arus ketika ON
int t_rise; // waktu ketika mulai v_on
int t_fall; // waktu ketika mulai v_init
int t_delay; // lama v_init / v_on bekerja sebelum berubah
int period; //periode gelombang
} current_source;

