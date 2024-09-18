use std::fs::File;
use std::io::{BufRead, BufReader};
use serde::{Deserialize, Serialize};
use yaml_rust::{Yaml, YamlLoader};

#[derive(Debug, Serialize, Deserialize)]

struct MarkdownFile {
    yaml: Option<Yaml>,
    content: String,
}

fn open_markdown_file(file_path: &str) -> Result<MarkdownFile, Box<dyn std::error::Error>> {
    let file = File::open(file_path)?;
    let reader = BufReader::new(file);

    let mut lines = reader.lines();

    let mut yaml_content = String::new();
    let mut content = String::new();

    let mut has_yaml = false;

    for line in lines {
        let line = line?;

        if !has_yaml && line.starts_with("---") {
            has_yaml = true;
            continue;
        }

        if has_yaml && line.starts_with("---") {
            break;
        }

        if has_yaml {
            yaml_content.push_str(&line);
            yaml_content.push('\n');
        } else {
            content.push_str(&line);
            content.push('\n');
        }
    }

    let yaml = if has_yaml {
        Some(YamlLoader::load_from_str(&yaml_content)?)
    } else {
        None
    };

    Ok(MarkdownFile { yaml, content })
}

fn main() {
    let file_path = r"C:\Users\lins0018\Documents\Rust\做房产中介的妈妈.md";

    let result = open_markdown_file(file_path);

    match result {
        Ok(markdown_file) => {
            if let Some(yaml) = markdown_file.yaml {
                println!("YAML content:");
                println!("{:?}", yaml);
            } else {
                println!("No YAML found.");
            }

            println!("Markdown content:");
            println!("{}", markdown_file.content);
        }
        Err(err) => {
            eprintln!("Error: {}", err);
        }
    }
}
