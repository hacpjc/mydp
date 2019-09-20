#ifndef SRC_SRC_DATAPLEN_H_
#define SRC_SRC_DATAPLANE_H_

int dataplane_exec(void);

int dataplane_init(int argc, char **argv);
void dataplane_exit(void);

#endif /* SRC_SRC_DATAPLANE_H_ */
