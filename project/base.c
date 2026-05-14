#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALAP_VERSION "0.1.0"

typedef struct {
    const char *id;
    const char *description;
    const char *filename;
    const char *content;
} Template;

static const Template templates[] = {
    {
        "c", "C source code",
        "main.c",
        "#include <stdio.h>\n"
        "\n"
        "int main(void) {\n"
        "    printf(\"Hello, World!\\n\");\n"
        "    return 0;\n"
        "}\n"
    },
    {
        "cpp", "C++ source code",
        "main.cpp",
        "#include <iostream>\n"
        "\n"
        "int main() {\n"
        "    std::cout << \"Hello, World!\" << std::endl;\n"
        "    return 0;\n"
        "}\n"
    },
    {
        "cs", "C# source code",
        "Program.cs",
        "using System;\n"
        "\n"
        "class Program {\n"
        "    static void Main(string[] args) {\n"
        "        Console.WriteLine(\"Hello, World!\");\n"
        "    }\n"
        "}\n"
    },
    {
        "flask", "Flask source code",
        "app.py",
        "from flask import Flask\n"
        "\n"
        "app = Flask(__name__)\n"
        "\n"
        "@app.route(\"/\")\n"
        "def index():\n"
        "    return \"Hello, World!\"\n"
        "\n"
        "if __name__ == \"__main__\":\n"
        "    app.run(debug=True)\n"
    },
    {
        "go", "Go source code",
        "main.go",
        "package main\n"
        "\n"
        "import \"fmt\"\n"
        "\n"
        "func main() {\n"
        "    fmt.Println(\"Hello, World!\")\n"
        "}\n"
    },
    {
        "java", "Java source code",
        "Main.java",
        "public class Main {\n"
        "    public static void main(String[] args) {\n"
        "        System.out.println(\"Hello, World!\");\n"
        "    }\n"
        "}\n"
    },
    {
        "py", "Python 3 source code",
        "main.py",
        "def main():\n"
        "    print(\"Hello, World!\")\n"
        "\n"
        "\n"
        "if __name__ == \"__main__\":\n"
        "    main()\n"
    },
    {
        "rust", "Rust source code",
        "main.rs",
        "fn main() {\n"
        "    println!(\"Hello, World!\");\n"
        "}\n"
    },
    {
        "sh", "Bash source code",
        "main.sh",
        "#!/usr/bin/env bash\n"
        "\n"
        "echo \"Hello, World!\"\n"
    }
};

static const int templates_count = sizeof(templates) / sizeof(templates[0]);

static void print_usage(void) {
    printf("alap v%s,\n\n", ALAP_VERSION);
    printf("Usage: alap <template_id> [option]\n\n");
    printf("Available options:\n\n");
    printf("-h, --help        show this help\n");
    printf("-v, --version     version info\n");
    printf("--stdout          don't create source file, print result to stdout\n\n");
    printf("Available templates:\n\n");
    for (int i = 0; i < templates_count; i++) {
        printf("  * %-6s - %s [%s]\n",
               templates[i].id,
               templates[i].description,
               templates[i].filename);
    }
}

static void print_version(void) {
    printf("alap v%s\n", ALAP_VERSION);
}

static const Template *find_template(const char *id) {
    for (int i = 0; i < templates_count; i++) {
        if (strcmp(templates[i].id, id) == 0) {
            return &templates[i];
        }
    }
    return NULL;
}

static int file_exists(const char *path) {
    FILE *f = fopen(path, "r");
    if (f) {
        fclose(f);
        return 1;
    }
    return 0;
}

static int write_template(const Template *t) {
    if (file_exists(t->filename)) {
        fprintf(stderr, "Error: file '%s' already exists.\n", t->filename);
        return 1;
    }

    FILE *f = fopen(t->filename, "w");
    if (!f) {
        fprintf(stderr, "Error: cannot create file '%s'.\n", t->filename);
        return 1;
    }
    fputs(t->content, f);
    fclose(f);

    printf("Created %s\n", t->filename);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_usage();
        return 0;
    }

    const char *arg = argv[1];

    if (strcmp(arg, "-h") == 0 || strcmp(arg, "--help") == 0) {
        print_usage();
        return 0;
    }

    if (strcmp(arg, "-v") == 0 || strcmp(arg, "--version") == 0) {
        print_version();
        return 0;
    }

    const Template *t = find_template(arg);
    if (!t) {
        fprintf(stderr, "Error: unknown template '%s'.\n\n", arg);
        print_usage();
        return 1;
    }

    int use_stdout = 0;
    if (argc >= 3) {
        if (strcmp(argv[2], "--stdout") == 0) {
            use_stdout = 1;
        } else {
            fprintf(stderr, "Error: unknown option '%s'.\n", argv[2]);
            return 1;
        }
    }

    if (use_stdout) {
        fputs(t->content, stdout);
        return 0;
    }

    return write_template(t);
}
