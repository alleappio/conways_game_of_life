mod conf;
use crate::TraceLogLevel::LOG_ERROR;
use std::process::exit;

use raylib::prelude::*;

use crate::conf::Conf;

fn main() {
    let conf_res = Conf::from_file("conf/conway.toml".to_string());
    let configuration: Conf = match conf_res {
        Err(e) => {
            std::eprintln!("Something's wrong, i can feel it {e}");
            exit(1);
        }
        Ok(c) => c,
    };

    let (mut rl, thread) = raylib::init()
        .size(configuration.screen.width, configuration.screen.height)
        .title("Conway's game of life")
        .log_level(LOG_ERROR)
        .build();

    while !rl.window_should_close() {
        let mut d = rl.begin_drawing(&thread);

        for i in 0..configuration.grid.width {
            let x = i*configuration.screen.width/configuration.grid.width;
            d.draw_line(x, 0, x, configuration.screen.height, configuration.colors.line_color);
        }
        for i in 0..configuration.grid.height {
            let y = i*configuration.screen.height/configuration.grid.height;
            d.draw_line(0, y, configuration.screen.width, y, configuration.colors.line_color);
        }
        d.clear_background(configuration.colors.background_color);
    }
}
