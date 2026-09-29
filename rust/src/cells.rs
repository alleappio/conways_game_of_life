pub struct Cells {
    grid_width: usize,
    grid_height: usize,
    pub cell_matrix: Vec<Vec<bool>>,
}

impl Cells {
    pub fn new(width: i32, height: i32) -> Self {
        Self {
            grid_width: width as usize,
            grid_height: height as usize,
            cell_matrix: vec![vec![false; width as usize]; height as usize],
        }
    }

    pub fn random_initialize(&mut self, alive_chance: i32) {
        for i in 0..self.grid_width {
            for j in 0..self.grid_height {
                self.cell_matrix[i][j] = match rand::random_range(0..alive_chance) {
                    1 => true,
                    _ => false,
                }
            }
        }
    }

    pub fn update(&mut self) {
        let mut new_matrix = vec![vec![false; self.grid_width]; self.grid_height];
        for i in 0..self.grid_height {
            for j in 0..self.grid_height {
                let count = self.get_neighbors_number(i, j);
                new_matrix[i][j] = self.apply_rules(count, self.cell_matrix[i][j]);
            }
        }
        self.cell_matrix = new_matrix;
    }

    fn get_neighbors_number(&mut self, x: usize, y: usize) -> i32 {
        let mut count = 0;
        for i in x as i32 - 1..x as i32 + 2 {
            for j in y as i32 - 1..y as i32 + 2 {
                if i >= 0
                    && j >= 0
                    && i < self.grid_width as i32
                    && j < self.grid_height as i32
                    && (i as usize != x || j as usize != y)
                {
                    if self.cell_matrix[i as usize][j as usize] {
                        count += 1;
                    }
                }
            }
        }
        count
    }

    fn apply_rules(&mut self, neighbors_number: i32, state: bool) -> bool {
        if state {
            if neighbors_number == 2 || neighbors_number == 3 {
                return true;
            }
        } else {
            if neighbors_number == 3 {
                return true;
            }
        }
        return false;
    }
}
