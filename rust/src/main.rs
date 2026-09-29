mod cells;
mod conf;
use crate::TraceLogLevel::LOG_ERROR;
use std::process::exit;

use raylib::prelude::*;

use crate::cells::Cells;
use crate::conf::Conf;

fn draw_grid(configuration: &Conf, d: &mut RaylibDrawHandle) {
    for i in 0..configuration.grid.width {
        let x = i * configuration.screen.width / configuration.grid.width;
        d.draw_line(
            x,
            0,
            x,
            configuration.screen.height,
            configuration.colors.line_color,
        );
    }
    for i in 0..configuration.grid.height {
        let y = i * configuration.screen.height / configuration.grid.height;
        d.draw_line(
            0,
            y,
            configuration.screen.width,
            y,
            configuration.colors.line_color,
        );
    }
}

fn draw_cells(cells: &mut Cells, config: &Conf, d: &mut RaylibDrawHandle) {
    for i in 0..config.grid.width as usize {
        for j in 0..config.grid.height as usize {
            if cells.cell_matrix[j][i] {
                let x1 = i as i32 * config.screen.width / config.grid.width;
                let y1 = j as i32 * config.screen.height / config.grid.height;

                let x2 = (i + 1) as i32 * config.screen.width / config.grid.width;
                let y2 = (j + 1) as i32 * config.screen.height / config.grid.height;
                d.draw_rectangle(x1, y1, x2 - x1, y2 - y1, config.colors.cell_color);
            }
        }
    }
}

fn main() {
    let conf_res = Conf::from_file("conf/conway.toml".to_string());
    let configuration: Conf = match conf_res {
        Err(e) => {
            std::eprintln!("Something's wrong, i can feel it {e}");
            exit(1);
        }
        Ok(c) => c,
    };

    let mut cells: Cells = Cells::new(configuration.grid.width, configuration.grid.height);
    cells.random_initialize();

    let (mut rl, thread) = raylib::init()
        .size(configuration.screen.width, configuration.screen.height)
        .title("Conway's game of life")
        .log_level(LOG_ERROR)
        .build();

    while !rl.window_should_close() {
        let mut d = rl.begin_drawing(&thread);

        d.clear_background(configuration.colors.background_color);
        draw_grid(&configuration, &mut d);
        draw_cells(&mut cells, &configuration, &mut d);
    }
}
