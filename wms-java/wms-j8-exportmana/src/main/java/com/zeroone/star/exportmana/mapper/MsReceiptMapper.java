package com.zeroone.star.exportmana.mapper;

import com.zeroone.star.exportmana.entity.Receipt;
import com.zeroone.star.project.dto.j8.shipmentmana.receiptmana.ReceiptBaseDTO;
import com.zeroone.star.project.dto.j8.shipmentmana.receiptmana.ReceiptListDTO;
import com.zeroone.star.project.dto.j8.shipmentmana.receiptmana.ReceiptPutDTO;
import org.mapstruct.Mapper;
import org.mapstruct.Mapping;

@Mapper(componentModel = "spring")
public interface MsReceiptMapper{
    @Mapping(source = "id",target = "id")
    @Mapping(source = "createUser",target = "createBy")
    @Mapping(source = "createTime",target = "createDate")
    @Mapping(source = "cargoOwner",target = "cusCode")
    @Mapping(source = "receiptId",target = "wmNoticeId")
    @Mapping(source = "hdTime",target = "hdData")
    @Mapping(source = "comment",target = "beizhu")
    Receipt ReceiptListDTOtoReceipt(ReceiptListDTO dto);

    @Mapping(source = "id",target = "id")
    @Mapping(source = "receiptId",target = "wmNoticeId")
    @Mapping(source = "hdTime",target = "hdData")
    @Mapping(source = "comment",target = "beizhu")
    Receipt ReceiptPutDTOtoReceipt(ReceiptPutDTO dto);

    @Mapping(source = "receiptId",target = "wmNoticeId")
    @Mapping(source = "hdTime",target = "hdData")
    @Mapping(source = "comment",target = "beizhu")
    Receipt ReceiptBaseDTOtoReceipt(ReceiptBaseDTO dto);

    @Mapping(source = "id",target = "id")
    @Mapping(source = "wmNoticeId",target = "receiptId")
    @Mapping(source = "hdData",target = "hdTime")
    @Mapping(source = "beizhu",target = "comment")
    @Mapping(source = "createName",target = "createUser")
    @Mapping(source = "createDate",target = "createTime")
    @Mapping(source = "cusCode",target = "cargoOwner")
    ReceiptListDTO toReceiptListDTO(Receipt receipt);
}