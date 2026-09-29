mod conf;
use std::process::exit;
use crate::TraceLogLevel::LOG_ERROR;

use raylib::prelude::*;

use crate::conf::Conf;


fn main() {
    let conf_res = Conf::from_file("conf/conway.toml".to_string());
    let configuration: Conf = match conf_res {
        Err(e) => {
            std::eprintln!("Something's wrong, i can feel it {e}");
            exit(1);
        }
        Ok(c) => c
    };

    let (mut rl, thread) = raylib::init()
        .size(640, 480)
        .title("Conway's game of life")
        .log_level(LOG_ERROR)
        .build();

    while !rl.window_should_close() {
        let mut d = rl.begin_drawing(&thread);

        d.clear_background(configuration.colors.background_color);
    }
}
