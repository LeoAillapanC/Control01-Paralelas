


string cambio(string sigla){
  switch(sigla)
{
    case 'SP':  {sigla='SO';break;}
    case 'SO': {sigla='SP';break;}
    case 'LH': {sigla='HE';break;}
    case 'HE': {sigla='LH';break;}
    case 'BA':  {sigla='BQ';break;}
    case 'BQ': {sigla='BA';break;}
    case 'LE': {sigla='LEN';break;}
    case 'LEN': {sigla='LE';break;}
    case 'TB': {sigla='TOB';break;}
    case 'TOB': {sigla='TB';break;}
    case 'LC': {sigla='LCI';break;}
    case 'LCI': {sigla='LC';break;}
    case 'AN': {sigla='NA';break;}
    case 'NA': {sigla='AN';break;}
    case 'FR': {sigla='FRA';break;}
    case 'VMA': {sigla='VIM';break;}
    case 'VIM': {sigla='VMA';break;}
    case 'VVA': {sigla='VV';break;}
    case 'VV': {sigla='VVA';break;}
    case 'NU': {sigla='NUO';break;}
    case 'NUO': {sigla='NU';break;}

   Return sigla;
}

  }



}
