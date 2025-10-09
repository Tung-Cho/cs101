 fp = fopen("cj.bin","wb+");
    fwrite(a,sizeof(a),1,fp);
    fseek(fp,0,SEEK_SET);
    fread(ra,sizeof(ra),1,fp);
