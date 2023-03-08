static bool reito_decode_XReito48(DisasContext *ctx, uint64_t insn)
{
    union {
        arg_reito_b f_reito_b;
        arg_reito_i f_reito_i;
        arg_reito_is f_reito_is;
        arg_reito_j f_reito_j;
        arg_reito_r f_reito_r;
        arg_reito_s f_reito_s;
        arg_reito_u f_reito_u;
    } u;

    switch (insn & 0x0000001c0000003full) {
    case 0x000000000000001f: 
        decode_XReito48_extract_reito_r(ctx, &u.f_reito_r, insn);
        if (trans_reito_r(ctx, &u.f_reito_r)) return true;
        break;
    case 0x000000040000001full: 
        decode_XReito48_extract_reito_i(ctx, &u.f_reito_i, insn);
        if (trans_reito_i(ctx, &u.f_reito_i)) return true;
        break;
    case 0x000000080000001full: 
        decode_XReito48_extract_reito_is6(ctx, &u.f_reito_is, insn);
        if (trans_reito_is6(ctx, &u.f_reito_is)) return true;
        break;
    case 0x0000000c0000001full: 
        decode_XReito48_extract_reito_is5(ctx, &u.f_reito_is, insn);
        if (trans_reito_is5(ctx, &u.f_reito_is)) return true;
        break;
    case 0x000000100000001full: 
        decode_XReito48_extract_reito_s(ctx, &u.f_reito_s, insn);
        if (trans_reito_s(ctx, &u.f_reito_s)) return true;
        break;
    case 0x000000140000001full: 
        decode_XReito48_extract_reito_b(ctx, &u.f_reito_b, insn);
        if (trans_reito_b(ctx, &u.f_reito_b)) return true;
        break;
    case 0x000000180000001full: 
        decode_XReito48_extract_reito_u(ctx, &u.f_reito_u, insn);
        if (trans_reito_u(ctx, &u.f_reito_u)) return true;
        break;
    case 0x0000001c0000001full: 
        decode_XReito48_extract_reito_j(ctx, &u.f_reito_j, insn);
        if (trans_reito_j(ctx, &u.f_reito_j)) return true;
        break;
    }
    return false;
}
