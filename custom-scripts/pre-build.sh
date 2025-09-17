#!/bin/sh

cp $BASE_DIR/../custom-scripts/S41network-config.sh $BASE_DIR/target/etc/init.d
chmod +x $BASE_DIR/target/etc/init.d/S41network-config.sh

cp $BASE_DIR/../custom-scripts/S50hello.sh $BASE_DIR/target/etc/init.d
chmod +x $BASE_DIR/target/etc/init.d/S50hello.sh

cp $BASE_DIR/../custom-scripts/S51systeminfo.sh $BASE_DIR/target/etc/init.d
chmod +x $BASE_DIR/target/etc/init.d/S51systeminfo.sh

make -C $BASE_DIR/../modules/simple_driver/

