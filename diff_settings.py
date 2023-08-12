def apply(config, args):
    config["arch"] = "mipsel"
    config['baseimg'] = f'MAIN_T.EXE'
    config['myimg'] = f'build/title.exe'
    config['mapfile'] = f'build/title.map'
    config['source_directories'] = [f'src/game', 'include', f'asm/game']