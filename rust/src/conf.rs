use raylib::ffi::Color;
use serde::{Deserialize, de::Error};

fn deserialize_color<'de, D>(deserializer: D) -> Result<Color, D::Error>
where
    D: serde::Deserializer<'de>,
{
    let hex = String::deserialize(deserializer)?;
    let hex = hex.strip_prefix('#').unwrap_or(&hex);

    if hex.len() != 6 {
        return Err(D::Error::custom("color must be in #RRGGBB format"));
    }

    let r = u8::from_str_radix(&hex[0..2], 16).map_err(D::Error::custom)?;
    let g = u8::from_str_radix(&hex[2..4], 16).map_err(D::Error::custom)?;
    let b = u8::from_str_radix(&hex[4..6], 16).map_err(D::Error::custom)?;

    Ok(Color { r, g, b, a: 255 })
}

#[derive(Deserialize)]
pub struct Screen {
    pub width: i32,
    pub height: i32,
}

#[derive(Deserialize)]
pub struct Grid {
    pub width: i32,
    pub height: i32,
}

#[derive(Deserialize)]
pub struct Game {
    pub alive_chance: i32,
    pub tick_millis: u64,
}

#[derive(Deserialize)]
pub struct Colors {
    #[serde(deserialize_with = "deserialize_color")]
    pub background_color: Color,
    #[serde(deserialize_with = "deserialize_color")]
    pub line_color: Color,
    #[serde(deserialize_with = "deserialize_color")]
    pub cell_color: Color,
}

#[derive(Deserialize)]
pub struct Conf {
    pub screen: Screen,
    pub grid: Grid,
    pub colors: Colors,
    pub game: Game,
}

impl Conf {
    pub fn from_file(path: String) -> Result<Conf, Box<dyn std::error::Error>> {
        let content = std::fs::read_to_string(&path)?;
        let config: Conf = toml::from_str(&content)?;
        Ok(config)
    }
}
