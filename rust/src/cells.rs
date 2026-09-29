pub struct Cells {
    cell_number: i32,
    grid_width: i32,
    grid_height: i32,
    pub cell_matrix: Vec<Vec<bool>>
}

impl Cells {
    pub fn new(width: i32, height: i32) -> Self {
        Self {
            grid_width: width,
            grid_height: height,
            cell_number: width * height,
            cell_matrix: vec![vec![false; width as usize]; height as usize]
        }
    }

    pub fn random_initialize(&mut self) {
        for i in 0..self.grid_width as usize {
            for j in 0..self.grid_height as usize {
                self.cell_matrix[i][j] = match rand::random_range(0..2) {
                    0 => false,
                    1 => true,
                    _ => true
                }
            }
        }
    }
}


